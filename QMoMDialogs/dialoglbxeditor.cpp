#include "dialoglbxeditor.h"
#include "ui_dialoglbxeditor.h"

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMessageBox>

#include "MoMUtility.h"
#include "QMoMLbx.h"
#include "QMoMResources.h"
#include "QMoMSettings.h"

DialogLbxEditor::DialogLbxEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLbxEditor),
    m_sceneBitmap(new QGraphicsScene(this)),
    m_sceneLbx(new QGraphicsScene(this)),
    m_filedialogLoad(new QFileDialog(this)),
    m_filedialogSave(new QFileDialog(this))
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window);
    setFont(MoM::QMoMResources::g_Font);
    ui->textEdit_lbxText->setFont(MoM::QMoMResources::g_FontFixed);

    ui->graphicsView_LbxImage->setScene(m_sceneLbx);
    ui->graphicsView_BitmapImage->setScene(m_sceneBitmap);

    ui->comboBox_LbxIndex->clear();
    ui->comboBox_LbxIndex->addItem("(Index in LBX file)");
    ui->comboBox_FileIndex->clear();
    ui->comboBox_FileIndex->addItem("(Images in directory containing the tweaker)");

    m_filedialogLoad->setObjectName("filedialogLoad");
    m_filedialogLoad->setWindowTitle(tr("Open LBX file"));
    m_filedialogLoad->setNameFilter(tr("LBX files (*.lbx)"));
    m_filedialogLoad->setAcceptMode(QFileDialog::AcceptOpen);
    m_filedialogLoad->setFileMode(QFileDialog::ExistingFile);
    m_filedialogLoad->setViewMode(QFileDialog::Detail);

    m_filedialogSave->setObjectName("filedialogSave");
    m_filedialogSave->setWindowTitle(tr("Save picture(s)"));
    m_filedialogSave->setNameFilter(tr("Pictures (*.png *.bmp *.gif *.jpg);;All files (*.*)"));
    m_filedialogSave->setDefaultSuffix("png");
    m_filedialogSave->setAcceptMode(QFileDialog::AcceptSave);
    m_filedialogSave->setFileMode(QFileDialog::AnyFile);
    m_filedialogSave->setViewMode(QFileDialog::Detail);

#ifdef _WIN32
    m_filedialogLoad->setDirectory("C:/GAMES/");
#else // Linux
//    m_filedialogLoad->setDirectory("/media/C_DRIVE/GAMES/MAGIC-work/");
#endif
    m_bitmapDirectory = QApplication::applicationDirPath();
    m_filedialogSave->setDirectory(m_bitmapDirectory);

    QMoMSettings::readSettingsWindow(this);

    listBitmapFiles(m_bitmapDirectory);
}

DialogLbxEditor::~DialogLbxEditor()
{
    QMoMSettings::writeSettingsWindow(this);

    delete ui;
}

QString DialogLbxEditor::constructFrameFilename(const QString& bitmapFilename, int frameNr)
{
    QString frameFilename = bitmapFilename;
    if (frameNr > 0)
    {
        int indexExt = frameFilename.lastIndexOf(QChar('.'));
        if ((indexExt > 0) && (frameFilename[indexExt - 1] == '0') && (frameNr < 10))
        {
            frameFilename[indexExt - 1] = QChar('0' + frameNr);
        }
        else if ((indexExt > 1) && (frameFilename[indexExt - 1] == '0') && (frameFilename[indexExt - 2] == '0') && (frameNr < 100))
        {
            frameFilename[indexExt - 2] = QChar('0' + frameNr / 10);
            frameFilename[indexExt - 1] = QChar('0' + frameNr % 10);
        }
        else
        {
            frameFilename = QString("%0_%1%2")
                            .arg(frameFilename.left(indexExt)).arg(frameNr).arg(frameFilename.mid(indexExt));
        }
    }
    return frameFilename;
}

void DialogLbxEditor::loadLbx(const QString& filename)
{
    if (!m_lbx.load(filename.toAscii().data()))
    {
        (void)QMessageBox::warning(this,
            tr("Load LBX"),
            tr("Can't load LBX file '%0'").arg(filename));
        return;
    }

    bool triedPalette = false;

    // Update caption
    setWindowTitle(filename);

    m_lbxAnimations.clear();
    m_lbxAnimations.resize(m_lbx.getNrRecords());

    ui->comboBox_LbxIndex->clear();
    for (size_t lbxIndex = 0; lbxIndex < m_lbx.getNrRecords(); ++lbxIndex)
    {
        const MoM::MoMLbxBase::Annotation* annotation = m_lbx.getAnnotation(lbxIndex);
        if (m_lbx.getNrSubRecords(lbxIndex) > 0)
        {
            std::vector<uint8_t> data;
            for (size_t lbxSubIndex = 0; lbxSubIndex < m_lbx.getNrSubRecords(lbxIndex); ++lbxSubIndex)
            {
                QString text = QString("%0-%1").arg(lbxIndex).arg(lbxSubIndex);
                if ((0 != annotation) && (annotation->subfile[0] != '\0'))
                {
                    text = text + " - " + annotation->subfile;
                }
                if ((0 != annotation) && (annotation->comment[0] != '\0'))
                {
                    text = text + " - " + annotation->comment;
                }
                if (m_lbx.getSubRecord(lbxIndex, lbxSubIndex, data)
                    && data.size() == sizeof(MoM::HelpLBXentry))
                {
                    MoM::HelpLBXentry* helpEntry = (MoM::HelpLBXentry*)&data[0];
                    text = text + " - " + helpEntry->title;
                }
                ui->comboBox_LbxIndex->addItem(text);
            }
        }
        else
        {
            QString text = QString("%0").arg(lbxIndex);
            if ((0 != annotation) && (annotation->subfile[0] != '\0'))
            {
                text = text + " - " + annotation->subfile;
            }
            if ((0 != annotation) && (annotation->comment[0] != '\0'))
            {
                text = text + " - " + annotation->comment;
            }

            MoM::MoMLbxBase::eRecordType recordType = m_lbx.getRecordType(lbxIndex);
            if (recordType == MoM::MoMLbxBase::TYPE_images)
            {
                if (!triedPalette)
                {
                    loadPaletteForFile(filename);
                    triedPalette = true;
                }

                (void)MoM::convertLbxToImages(m_lbx.getRecord(lbxIndex), m_lbx.getRecordSize(lbxIndex), m_colorTable,
                                              m_lbxAnimations[lbxIndex], MoM::toStr(lbxIndex));
                QPixmap pixmap;
                if (!m_lbxAnimations[lbxIndex].isEmpty() && (0 != m_lbxAnimations[lbxIndex][0]))
                {
                    pixmap.convertFromImage(*m_lbxAnimations[lbxIndex][0]);
                }
                ui->comboBox_LbxIndex->addItem(QIcon(pixmap), text);
            }
            else
            {
                ui->comboBox_LbxIndex->addItem(text);
            }
        }
    }

    if (ui->comboBox_LbxIndex->count() > 0)
    {
        ui->comboBox_LbxIndex->setCurrentIndex(0);
    }
}

void DialogLbxEditor::loadPaletteForFile(const QString &filename)
{
    m_colorTable.clear();

    QFileInfo fileInfo(filename);
    QString gameDirectory = fileInfo.absoluteDir().absolutePath();
    QString filetitle = fileInfo.fileName();
    int lbxIndex = 0;

    if (0 == filetitle.compare("LOAD.LBX", Qt::CaseInsensitive))
    {
        lbxIndex = 3;
    }
    else if (0 == filetitle.compare("MAINSCRN.LBX", Qt::CaseInsensitive))
    {
        lbxIndex = 4;
    }
    else if (0 == filetitle.compare("WIZLAB.LBX", Qt::CaseInsensitive))
    {
        lbxIndex = 5;
    }
    else if (0 == filetitle.compare("SPLMASTR.LBX", Qt::CaseInsensitive))
    {
        lbxIndex = 6;
    }
    else if (0 == filetitle.compare("WIN.LBX", Qt::CaseInsensitive))
    {
        lbxIndex = 7;
    }
    else if ((0 == filetitle.compare("LOSE.LBX", Qt::CaseInsensitive))
             || (0 == filetitle.compare("SPELLOSE.LBX", Qt::CaseInsensitive)))
    {
        lbxIndex = 8;
    }
    else
    {
        lbxIndex = 2;
    }

    std::string fontsLbxFile = std::string(gameDirectory.toAscii()) + "/" + "FONTS.LBX";
    m_colorTable.resize(256);
    MoM::MoMLbxBase fontsLbx;
    if (!fontsLbx.load(fontsLbxFile))
    {
        (void)QMessageBox::warning(this,
            tr("Load LBX"),
            tr("Can't load FONTS.LBX file needed for the palette (%0)")
                                   .arg(fontsLbxFile.c_str()));
        return;
    }

    uint8_t* dataPalette = fontsLbx.getRecord(lbxIndex);
    MoM::convertLbxToPalette(dataPalette, m_colorTable);
}

void DialogLbxEditor::updateBitmapImage(const QString& bitmapFilename)
{
    // Track converted image for later use
    m_bitmapAnimation.clear();

    int nframes = 1;
    int lbxIndex = ui->comboBox_LbxIndex->currentIndex();
    if ((lbxIndex >= 0) && (lbxIndex < m_lbxAnimations.count()) && (m_lbxAnimations[lbxIndex].count() > 1))
    {
        nframes = m_lbxAnimations[lbxIndex].count();
    }

    // Load bitmap(s) into an Animation
    MoM::QMoMAnimation origAnimation;
    int height = 0;
    for (int frameNr = 0; frameNr < nframes; ++frameNr)
    {
        QString frameFilename = constructFrameFilename(bitmapFilename, frameNr);
        if (frameFilename.isEmpty())
        {
            break;
        }
        QMoMImagePtr origImage(new QImage(frameFilename));
        if (origImage->isNull() || (origImage->width() <= 1))
        {
            // try to load as fli
            MoM::MoMFli fli;
            if (fli.load(frameFilename.toAscii().data()))
            {
                // Set pixels
                QImage fliImage(fli.getPixels(), fli.getWidth(), fli.getHeight(), QImage::Format_Indexed8);

                // Set color table
                QVector<QRgb> colorTable(256);
                const uint8_t* dataPalette = fli.getPalette();
                for (int i = 0; i < colorTable.size(); ++i)
                {
                    colorTable[i] = qRgb(4 * dataPalette[3*i], 4 * dataPalette[3*i+1], 4 * dataPalette[3*i+2]);
                }
                fliImage.setColorTable(colorTable);

                fliImage.save("scrdmp.png");

                // Copy
                origImage = QMoMImagePtr(new QImage(fliImage.copy()));
            }
        }

        origAnimation.append(origImage);
        if (origImage->height() > height)
        {
            height = origImage->height();
        }
    }

    MoM::QMoMAnimation convertedAnimation;
    for (int frameNr = 0; frameNr < origAnimation.count(); ++frameNr)
    {
        QMoMImagePtr origImage = origAnimation[frameNr];

        if ((0 != origImage) && (origImage->width() > 0) && (!m_colorTable.isEmpty()))
        {
            // Convert image to MoM format

            // Adjust color table for proper color matching
            MoM::QMoMPalette colorTable(m_colorTable);
            colorTable.resize(244);
            colorTable[0] = qRgb(255, 0, 255);                  // Treat MAGENTA RGB(255, 0, 255) as TRANSPARENT (0)!
            colorTable[MoM::gSHADOW_COLOR] = qRgb(0, 255, 0);   // Treat GREEN RGB(0, 255, 0) as SHADOW (232)

            // Convert image
            QMoMImagePtr saveImage(new QImage(origImage->convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor)));

            convertedAnimation.append(saveImage);
        }
    }

    std::vector<uint8_t> dataBuffer;
    (void)MoM::convertImagesToLbx(convertedAnimation, dataBuffer, "LbxEditor");

    // Track converted image for later use
    if (dataBuffer.size() > 0)
    {
        (void)MoM::convertLbxToImages(&dataBuffer[0], dataBuffer.size(), m_colorTable, m_bitmapAnimation, "LbxEditor");
    }

    // Show the converted image(s) together with the original image(s) in the graphics view
    updateImage(ui->graphicsView_BitmapImage, origAnimation);
    updateImage(ui->graphicsView_BitmapImage, m_bitmapAnimation, 1, false);
}

void DialogLbxEditor::updateLbxImage(int lbxIndex)
{
    MoM::QMoMAnimation curAnimation;
    if ((lbxIndex >= 0) && (lbxIndex < m_lbxAnimations.count()))
    {
        curAnimation = m_lbxAnimations[lbxIndex];
    }

    updateImage(ui->graphicsView_LbxImage, curAnimation);

    int width = 0;
    int height = 0;
    if (!curAnimation.isEmpty() && (0 != curAnimation[0]))
    {
        QMoMImagePtr& image = curAnimation[0];
        width = image->width();
        height = image->height();
        ui->label_Status->setText(QString("%0 x %1, %2 image(s)").arg(width).arg(height).arg(curAnimation.size()));
    }
}

void DialogLbxEditor::updateLbxText(int lbxIndex, int lbxSubIndex)
{
    ui->textEdit_lbxText->clear();

    std::vector<uint8_t> data;
    QString text;
    if (m_lbx.getSubRecord(lbxIndex, lbxSubIndex, data))
    {
        if (data.size() == sizeof(MoM::HelpLBXentry))
        {
            MoM::HelpLBXentry* helpEntry = (MoM::HelpLBXentry*)&data[0];
            text = helpEntry->description;
            // Replace code for newline by actual newline
            text.replace("\x14", "\n");
            ui->label_Status->setText(QString("%0 bytes, '%1' %2")
                .arg(data.size()).arg(helpEntry->lbxFile).arg(helpEntry->lbxIndex));
        }
        else
        {
            text = MoM::formatBufferAsHex(data).c_str();
            ui->label_Status->setText(QString("%0 bytes").arg(data.size()));
        }
    }
    else
    {
        (void)m_lbx.getRecord(lbxIndex, data);
        text = QString("(No text, %0 bytes)\n").arg(data.size());
        text += MoM::formatBufferAsHex(data).c_str();
    }
    ui->textEdit_lbxText->setText(text);
}

void DialogLbxEditor::updateImage(QGraphicsView *view, const MoM::QMoMAnimation& curAnimation, int line, bool clearImage)
{
    if (clearImage)
    {
        view->scene()->clear();
    }

    int height = 0;
    for(int i = 0; i < curAnimation.count(); ++i)
    {
        const QMoMImagePtr& curImage = curAnimation[i];
        if ((0 != curImage) && (curImage->height() > height))
        {
            height = curImage->height();
        }
    }

    QPointF pos;
    for(int i = 0; i < curAnimation.count(); ++i)
    {
        const QMoMImagePtr& curImage = curAnimation[i];
        if (0 == curAnimation[i])
            break;

        double scale = 3.0;
        if ((scale * curImage->width() > view->width())
                || (scale * curImage->height() > view->height()))
        {
            scale = 1.0;
        }

        QPixmap pixmap;
        QImage image = curImage->scaled(curImage->size() * scale, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        pixmap.convertFromImage(image);

        QGraphicsItem* itemRect = view->scene()->addRect(pixmap.rect(), QPen(Qt::NoPen), QBrush(QColor(255, 128, 255, 255)));
        QGraphicsItem* itemPixmap = view->scene()->addPixmap(pixmap);

        pos.setY(line * scale * (height + 4));
        itemRect->setPos(pos);
        itemPixmap->setPos(pos);

        pos.rx() += pixmap.width() + 4;
    }
}

void DialogLbxEditor::listBitmapFiles(const QString &directory)
{
    ui->comboBox_FileIndex->clear();
    ui->comboBox_FileIndex->addItem(QString("(Images in '%0')").arg(directory));
    QDir subdirs(directory);
    subdirs.setFilter(QDir::AllDirs | QDir::NoDotDot);
    foreach(QString subdir, subdirs.entryList())
    {
        QDir dir(directory + "/" + subdir, "*.bmp *.gif *.jpg *.png *.fli");
        foreach(QString filename, dir.entryList())
        {
            ui->comboBox_FileIndex->addItem(QIcon(), subdir + "/" + filename);
        }
    }
}

void DialogLbxEditor::on_comboBox_LbxIndex_currentIndexChanged(int index)
{
    QString currentText = ui->comboBox_LbxIndex->currentText();
    QStringList strings = currentText.split("-");
    int lbxIndex = index;
    int lbxSubIndex = 0;
    if (strings.size() >= 2)
    {
        lbxIndex = strings[0].toInt();
        lbxSubIndex = strings[1].toInt();
    }
    else if (strings.size() >= 1)
    {
        lbxIndex = strings[0].toInt();
    }

    ui->label_Status->clear();

    updateLbxImage(lbxIndex);
    updateLbxText(lbxIndex, lbxSubIndex);
}

void DialogLbxEditor::on_comboBox_FileIndex_currentIndexChanged(const QString &arg1)
{
    updateBitmapImage(m_bitmapDirectory + "/" + arg1);
}

void DialogLbxEditor::on_pushButton_Load_clicked()
{
    if (m_filedialogLoad->exec())
    {
        QString filename = m_filedialogLoad->selectedFiles().first();
        m_lbxDirectory = QFileInfo(filename).absoluteDir().absolutePath();

        loadLbx(filename);
    }
}

void DialogLbxEditor::on_pushButton_SavePics_clicked()
{
    MoM::QMoMAnimation curAnimation;
    int lbxIndex = ui->comboBox_LbxIndex->currentIndex();
    if ((lbxIndex >= 0) && (lbxIndex < m_lbxAnimations.count()))
    {
        curAnimation = m_lbxAnimations[lbxIndex];
    }
    if ((curAnimation.size() <= 0) || (0 == curAnimation[0]))
    {
        (void)QMessageBox::warning(this,
            tr("Save picture(s)"),
            tr("There are no pictures to save"));
        return;
    }

    if (m_filedialogSave->exec())
    {
        QString filenameBase = m_filedialogSave->selectedFiles().first();

        for (int frameNr = 0; frameNr < curAnimation.size(); ++frameNr)
        {
            QMoMImagePtr& image = curAnimation[frameNr];
            if (0 == image)
                continue;
            QString filename = constructFrameFilename(filenameBase, frameNr);
            if (!image->save(filename))
            {
                (void)QMessageBox::warning(this,
                    tr("Save picture(s)"),
                    tr("Failed to save the picture(s)"));
                break;
            }
        }
    }
}

void DialogLbxEditor::on_pushButton_Replace_clicked()
{
    int lbxIndex = ui->comboBox_LbxIndex->currentIndex();

    if ((lbxIndex < 0) || (lbxIndex >= m_lbxAnimations.count()) || (m_lbxAnimations[lbxIndex].count() != m_bitmapAnimation.count()))
    {
        (void)QMessageBox::warning(this,
            tr("Replace LBX"),
            tr("Please select an LBX set of images and replace them by the same number"));
        return;
    }

    if ((m_lbxAnimations[lbxIndex][0]->width() != m_bitmapAnimation[0]->width())
            || (m_lbxAnimations[lbxIndex][0]->height() != m_bitmapAnimation[0]->height()))
    {
        (void)QMessageBox::warning(this,
            tr("Replace LBX"),
            tr("Please replace the image with one with the same width (%0) and height (%1)")
                                   .arg(m_lbxAnimations[lbxIndex][0]->width())
                                   .arg(m_lbxAnimations[lbxIndex][0]->height())
            );
        return;
    }

    std::vector<uint8_t> dataBuffer;
    bool ok = MoM::convertImagesToLbx(m_bitmapAnimation, dataBuffer, "LbxEditor");
    if (ok)
    {
        ok = m_lbx.replaceRecord(lbxIndex, dataBuffer);
    }
    if (ok)
    {
        ok = m_lbx.save(m_lbx.getFilename());
    }

    if (ok)
    {
        (void)QMessageBox::information(this,
            tr("Replace LBX"),
            tr("Replaced LBX file '%0'").arg(m_lbx.getFilename().c_str()));
    }
    else
    {
        (void)QMessageBox::warning(this,
            tr("Replace LBX"),
            tr("Failed to replace LBX file '%0'").arg(m_lbx.getFilename().c_str()));
    }
}
