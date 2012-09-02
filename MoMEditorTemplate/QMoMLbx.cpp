// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <cassert>
#include <iomanip>
#include <iostream>

#include "QMoMLbx.h"

namespace MoM
{

namespace
{

void dump(const uint8_t* ptr, unsigned n)
{
    //std::cout << ":";
    //for (unsigned i = 0; i < n; ++i)
    //{
    //    if (i > 0)
    //    {
    //        std::cout << " ";
    //    }
    //    std::cout << std::hex << std::setw(2) << std::setfill('0') << (unsigned)*ptr++;
    //}
}

void dumpnl(const uint8_t* ptr, unsigned n)
{
    //dump(ptr, n);
    //std::cout << std::dec << std::endl;
}

}

bool convertImagesToLbx(const QMoMAnimation& images, std::vector<uint8_t>& dataBuffer, const std::string& context)
{
    if (images.empty())
        return false;

    assert(0 != images[0]);
    const QImage& image0 = *images[0];

    size_t upper_bound = 65536;
    if (images.size() * image0.width() * image0.height() > (int)upper_bound / 2)
    {
        return false;
    }

    dataBuffer.resize(upper_bound); // Upper bound
    uint8_t* data = &dataBuffer[0];
    size_t dataOffset = 0;

    // Encode header
    *(uint16_t*)(data + 0) = image0.width();
    *(uint16_t*)(data + 2) = image0.height();
    *(uint16_t*)(data + 6) = images.size();
    *(uint16_t*)(data + 14) = 0;        // No internal palette
    *(uint16_t*)(data + 16) = 1;        // ??? Copied from original MoM image
    uint32_t* frameOffsets = (uint32_t*)(data + 18);
    uint8_t* ptr = (uint8_t*)(frameOffsets + (images.size() + 1));

    frameOffsets[0] = dataOffset + (ptr - data);

    for (int imageNr = 0; imageNr < images.size(); ++imageNr)
    {
        assert(0 != images[imageNr]);
        const QImage& image = *images[imageNr];

        // TODO: check width, height
        // TODO: check encoding is 8-bit indexed (assumed to be corresponding to the default palette)

        *ptr++ = '\x01';       // Identify full frame (00=incremental, 01=full)
        for (int x = 0; x < image.width(); ++x)
        {
            int y = 0;
            int prev_y = y;

            // Find first non-transparent
            for (; y < image.height(); ++y)
            {
                uint8_t value = image.pixelIndex(x, y);
                if ((gTRANSPARENT_COLOR != value) && (255 != value))
                {
                    break;
                }
            }
            if (y >= image.height())
            {
                *ptr++ = '\xFF';    // Empty line
                continue;
            }

            uint8_t* row_ptr = ptr;
            *ptr++ = '\x00';                            // Code for Absolute values (i.e. NON-RLE)
            *ptr++ = image.height() + 2;                // Upper estimate for Bytes in row

            while (y < image.height())
            {
                uint8_t* seq_ptr = ptr;
                *ptr++ = image.height();                    // Upper estimate for Bytes in sequence
                *ptr++ = y - prev_y;                        // Delta y

                // Copy pixels until transparent pixel found
                for (; y < image.height(); ++y)
                {
                    uint8_t value = image.pixelIndex(x, y);
                    if ((gTRANSPARENT_COLOR == value) || (255 == value))
                    {
                        break;
                    }
                    *ptr++ = value;
               }

                seq_ptr[0] = (uint8_t)(ptr - seq_ptr - 2);  // Update Bytes in sequence
                prev_y = y;

                // Find next non-transparent
                for (; y < image.height(); ++y)
                {
                    uint8_t value = image.pixelIndex(x, y);
                    if ((gTRANSPARENT_COLOR != value) && (255 != value))
                    {
                        break;
                    }
                }
            }

            row_ptr[1] = (uint8_t)(ptr - row_ptr - 2);  // Update Bytes in row
        }

        frameOffsets[imageNr + 1] = dataOffset + (ptr - data);
    }

    dataBuffer.resize(ptr - data);

    return true;
}

bool convertLbxToImages(const uint8_t* data, const QMoMPalette& defaultColorTable, QMoMAnimation& images, const std::string& context)
{
    if (0 == data)
        return false;

    images.clear();

    // Extract header
    uint16_t width = *(uint16_t*)(data + 0);
    uint16_t height = *(uint16_t*)(data + 2);
    uint16_t nframes = *(uint16_t*)(data + 6);
    uint16_t paletteInfoOffset = *(uint16_t*)(data + 14);
    uint32_t* frameOffsets = (uint32_t*)(data + 18);

    uint16_t firstPaletteColorIndex = 0;
    uint16_t paletteColorCount = 255;

    QMoMPalette colorTable(defaultColorTable);

//std::cout << "Images: context=" << context << "\n"
//    << " width=" << (unsigned)width
//    << " height=" << (unsigned)height
//    << " nframes=" << (unsigned)nframes
//    << " paletteInfoOffset=" << (unsigned)paletteInfoOffset
//    << std::endl;

    // TODO: Range checks
    int nimages = nframes;
    if (nframes < 1)
    {
        nimages = 1;        // ??? nframes == 0 is code for uncompressed ???
    }

    bool ok = true;

    // Decode palette if present
    if (paletteInfoOffset > 0)
    {
        uint16_t paletteOffset = *(uint16_t*)(data + paletteInfoOffset);
        firstPaletteColorIndex = *(uint16_t*)(data + paletteInfoOffset + 2);
        paletteColorCount = *(uint16_t*)(data + paletteInfoOffset + 4);

//std::cout << "Palette: " << "\n"
//    << " paletteOffset=" << (unsigned)paletteOffset
//    << " firstPaletteColorIndex=" << (unsigned)firstPaletteColorIndex
//    << " paletteColorCount=" << (unsigned)paletteColorCount
//    << std::endl;
        if (firstPaletteColorIndex + paletteColorCount > colorTable.size())
        {
            colorTable.resize(firstPaletteColorIndex + paletteColorCount);
        }
        uint8_t* palette = (uint8_t*)(data + paletteOffset);
        for (size_t i = 0; i < paletteColorCount; ++i)
        {
dumpnl(palette + 3 * i, 3);
            colorTable[firstPaletteColorIndex + i] = qRgb(4 * palette[3*i], 4 * palette[3*i+1], 4 * palette[3*i+2]);
        }
    }

    images.resize(nimages);

    // Create images
    for (int frameNr = 0; frameNr < nimages; ++frameNr)
    {
//std::cout << "Frame=" << frameNr << std::endl;
        // Create empty image
        images[frameNr] = QMoMImagePtr(new QImage(width, height, QImage::Format_Indexed8));
        QImage& image = *images[frameNr];

        // Set color table
        image.setColorTable(colorTable);

        // Fill with transparent color
        images[frameNr]->fill(gTRANSPARENT_COLOR);

        const uint8_t* ptr = data;
        if (nframes > 0)
        {
//std::cout << "frameOffset=" << frameOffsets[frameNr] << std::endl;
            ptr += frameOffsets[frameNr];
dumpnl(ptr, 1);

            uint8_t frameCode = *ptr++;     // TODO: Check - Should be 01 for first frame,
                                            //       and either 00 (incremental), or 01 (complete) for the following frames
            if ((0 == frameCode) && (frameNr > 0))
            {
                // Copy previous image
                image = QImage(*images[frameNr - 1]);
            }
            else if (1 != frameCode)
            {
                std::cout << "Lbx bitmap '" << context << "' has unexpected frameCode " << (unsigned)frameCode << std::endl;
                ok = false;
            }

            for (int row = 0; ok && (row < width); ++row)
            {
                int x = row;
                if (0xFF == *ptr)
                {
                    // Empty line
dumpnl(ptr, 1);
                    ptr++;
                    continue;
                }
                else if ((0x00 == *ptr) || (0x80 == *ptr))
                {
                    // Sequence(s)
dump(ptr, 2);
                    uint8_t rowCode = *ptr++;
                    uint8_t nrowbytes = *ptr++;
                    const uint8_t* endrow_ptr = ptr + nrowbytes;
                    int y = 0;
                    while (ok && (ptr < endrow_ptr))
                    {
dump(ptr, 2);
                        uint8_t nseqbytes = *ptr++;
                        uint8_t delta = *ptr++;
                        y += delta;
dump(ptr, nseqbytes);
                        const uint8_t* endseq_ptr = ptr + nseqbytes;
                        while (ok && (ptr < endseq_ptr))
                        {
                            uint8_t value = *ptr++;
                            if ((0x80 == rowCode) && (value >= 0xE0))
                            {
                                value -= 0xDF;
                                while (value-- > 0)
                                {
                                    if (0 == *ptr)
                                    {
                                        std::cout << "Lbx bitmap '" << context << "' has (repeated) color 0 at x = " << x << " y = " << y << " offset(d) = " << (unsigned)(ptr - data) << std::endl;
                                        ok = false;
                                        break;
                                    }
                                    if (y >= height)
                                    {
                                        std::cout << "Lbx bitmap '" << context << "' has (repeated) coordinate out-of-range at x = " << x << " y = " << y << " offset(d) = " << (unsigned)(ptr - data) << std::endl;
                                        ok = false;
                                        break;
                                    }
                                    if (*ptr >= colorTable.size())
                                    {
                                        std::cout << "Lbx bitmap '" << context << "' has (repeated) value " << (unsigned)*ptr << " out-of-range at x = " << x << " y = " << y << " offset(d) = " << (unsigned)(ptr - data) << std::endl;
                                        ok = false;
                                        break;
                                    }
                                    image.setPixel(x, y, *ptr);
                                    y++;
                                }
                                ptr++;
                            }
                            else
                            {
                                if (0 == value)
                                {
                                    //std::cout << "Lbx bitmap '" << context << "' has color 0 at x = " << x << " y = " << y << " offset(d) = " << (unsigned)(ptr - data) << std::endl;
                                }
                                if (y >= height)
                                {
                                    std::cout << "Lbx bitmap '" << context << "' has coordinate out-of-range at x = " << x << " y = " << y << " offset(d) = " << (unsigned)(ptr - data) << std::endl;
                                    ok = false;
                                    break;
                                }
                                if (value >= colorTable.size())
                                {
                                    std::cout << "Lbx bitmap '" << context << "' has value " << (unsigned)value << " out-of-range at x = " << x << " y = " << y << " offset(d) = " << (unsigned)(ptr - data) << std::endl;
                                    ok = false;
                                    break;
                                }
                                image.setPixel(x, y, value);
                                y++;
                            }
                        }
                    }
dumpnl(ptr, 0);
                }
                else
                {
dumpnl(ptr, 1);
                    std::cout << "Lbx bitmap '" << context << "' has unknown directive " << (unsigned)*ptr << " at x = " << x << " offset(d) = " << (unsigned)(ptr - data) << std::endl;
                    ok = false;
                    break;
                }
            }
//if ((frameNr + 1 < nframes) && (ptr < data + frameOffsets[frameNr+1]))
//{
//std::cout << "Remaining bytes: " << std::endl;
//dumpnl(ptr, (unsigned)(data + frameOffsets[frameNr+1] - ptr));
//}
        }
        else
        {
            // ??? Uncompressed ???
//std::cout << "??? Uncompressed ???" << std::endl;
dumpnl(ptr, 16);
            ptr += 16;

            for (int row = 0; ok && (row < width); ++row)
            {
                int x = row;
dumpnl(ptr, height);
                for (int y = 0; y < height; ++y)
                {
                    image.setPixel(x, y, *ptr);
                    ptr++;
                }
            }
        }
dumpnl(ptr, 0);
    }
dumpnl(0, 0);

    return ok;
}

void convertLbxToPalette(const uint8_t* dataPalette, QMoMPalette& colorTable)
{
    for (int i = 0; i < 256; ++i)
    {
//        if ((i > 0) && (0 == dataPalette[3*i]) && (0 == dataPalette[3*i+1]) && (0 == dataPalette[3*i+2]))
//        {
//            colorTable[i] = qRgb(255, 0, 255);
////            colorTable.resize(i);
////            break;
//        }
//        else
        {
            colorTable[i] = qRgb(4 * dataPalette[3*i], 4 * dataPalette[3*i+1], 4 * dataPalette[3*i+2]);
        }
    }
    // Set transparent color
    colorTable[gTRANSPARENT_COLOR] = qRgba(0, 0, 0, 0);
}

}
