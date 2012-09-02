#include "dialoglbxeditor.h"
#include "ui_dialoglbxeditor.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMessageBox>

#include "QMoMLbx.h"
#include "QMoMResources.h"

DialogLbxEditor::DialogLbxEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLbxEditor),
    m_sceneBitmap(new QGraphicsScene(this)),
    m_sceneLbx(new QGraphicsScene(this))
{
    ui->setupUi(this);

    setFont(MoM::QMoMResources::g_Font);

    ui->graphicsView_LbxImage->setScene(m_sceneLbx);
    ui->graphicsView_BitmapImage->setScene(m_sceneBitmap);

    ui->comboBox_LbxIndex->clear();
    ui->comboBox_LbxIndex->addItem("(Index in LBX file)");
    ui->comboBox_FileIndex->clear();
    ui->comboBox_FileIndex->addItem("(Images in directory containing the tweaker)");

    m_filedialogLoad.setWindowTitle(tr("Open LBX file"));
    m_filedialogLoad.setNameFilter(tr("LBX files (*.lbx)"));
    m_filedialogLoad.setAcceptMode(QFileDialog::AcceptOpen);
    m_filedialogLoad.setFileMode(QFileDialog::ExistingFile);
    m_filedialogLoad.setViewMode(QFileDialog::Detail);

#ifdef _WIN32
    m_filedialogLoad.setDirectory("C:/games/MAGIC-work/");
#else // Linux
    m_filedialogLoad.setDirectory("/media/C_DRIVE/GAMES/MAGIC-work/");
#endif

    m_bitmapDirectory = QApplication::applicationDirPath();
    listBitmapFiles(m_bitmapDirectory);
}

DialogLbxEditor::~DialogLbxEditor()
{
    delete ui;
}

QString DialogLbxEditor::constructFrameFilename(const QString& bitmapFilename, int frameNr)
{
    QString frameFilename = bitmapFilename;
    if (frameNr > 0)
    {
        int indexExt = frameFilename.lastIndexOf(QChar('.'));
        if ((indexExt > 0) && (frameFilename[indexExt - 1] == '0'))
        {
            frameFilename[indexExt - 1] = QChar('0' + frameNr);
        }
        else
        {
            frameFilename.clear();
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

    QFileInfo fileInfo(filename);
    QString gameDirectory = fileInfo.absoluteDir().absolutePath();
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

    uint8_t* dataPalette = fontsLbx.getRecord(2);
    MoM::convertLbxToPalette(dataPalette, m_colorTable);

    m_lbxAnimations.resize(m_lbx.getNrRecords());
    for (size_t i = 0; i < m_lbx.getNrRecords(); ++i)
    {
        (void)MoM::convertLbxToImages(m_lbx.getRecord(i), m_colorTable, m_lbxAnimations[i], MoM::toStr(i));
    }

    int curIndex = ui->comboBox_LbxIndex->currentIndex();
    ui->comboBox_LbxIndex->clear();
    for (int i = 0; i < m_lbxAnimations.size(); ++i)
    {
        QPixmap pixmap;
        if (!m_lbxAnimations[i].isEmpty())
        {
            pixmap.convertFromImage(*m_lbxAnimations[i][0]);
        }
        ui->comboBox_LbxIndex->addItem(QIcon(pixmap), QString("%0").arg(i));
    }

    if (ui->comboBox_LbxIndex->count() > 0)
    {
        if ((curIndex < 0) || (curIndex >= ui->comboBox_LbxIndex->count()))
        {
            curIndex = 0;
        }
        ui->comboBox_LbxIndex->setCurrentIndex(curIndex);
    }
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
        (void)MoM::convertLbxToImages(&dataBuffer[0], m_colorTable, m_bitmapAnimation, "LbxEditor");
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
        QDir dir(directory + "/" + subdir, "*.bmp *.gif *.jpg *.png");
        foreach(QString filename, dir.entryList())
        {
            ui->comboBox_FileIndex->addItem(QIcon(), subdir + "/" + filename);
        }
    }
}

void DialogLbxEditor::on_comboBox_LbxIndex_currentIndexChanged(int index)
{
    updateLbxImage(index);
}

void DialogLbxEditor::on_comboBox_FileIndex_currentIndexChanged(const QString &arg1)
{
    updateBitmapImage(m_bitmapDirectory + "/" + arg1);
}

void DialogLbxEditor::on_pushButton_Load_clicked()
{
    if (m_filedialogLoad.exec())
    {
        QString filename = m_filedialogLoad.selectedFiles().first();
        m_lbxDirectory = QFileInfo(filename).absoluteDir().absolutePath();

        loadLbx(filename);
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
