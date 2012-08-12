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
}

DialogLbxEditor::~DialogLbxEditor()
{
    delete ui;
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

    // Load bitmap into an Animation
    QMoMImagePtr origImage(new QImage(bitmapFilename));
    Animation animation;
    animation.append(origImage);

    if ((0 != origImage) && (origImage->width() > 0) && (!m_colorTable.isEmpty()))
    {
        // Convert image to MoM format

        // Adjust color table for proper color matching
        QVector<QRgb> colorTable(m_colorTable);
        colorTable.resize(244);
        colorTable[0] = qRgb(255, 0, 255);  // Treat MAGENTA RGB(255, 0, 255) as TRANSPARENT!
        colorTable[232] = qRgb(0, 255, 0);    // Treat GREEN RGB(0, 255, 0) as SHADOW (232 or 239??)

        // Convert image
        QMoMImagePtr saveImage(new QImage(origImage->convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor)));

        // Track converted image for later use
        m_bitmapAnimation.append(saveImage);

        // Show (fow now) the converted image together with the original image in the graphics view
        animation.append(saveImage);
    }

    updateImage(ui->graphicsView_BitmapImage, animation);
}

void DialogLbxEditor::updateLbxImage(int lbxIndex)
{
    Animation curAnimation;
    if ((lbxIndex >= 0) && (lbxIndex < m_lbxAnimations.count()))
    {
        curAnimation = m_lbxAnimations[lbxIndex];
    }

    updateImage(ui->graphicsView_LbxImage, curAnimation);
}

void DialogLbxEditor::updateImage(QGraphicsView *view, const Animation& curAnimation)
{
    view->scene()->clear();
    QPointF pos(0, 0);

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

        itemRect->setPos(pos);
        itemPixmap->setPos(pos);

        pos.rx() += pixmap.width() + 4;
    }
}

void DialogLbxEditor::listBitmapFiles(const QString &directory)
{
    ui->comboBox_FileIndex->clear();
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

        if (m_bitmapDirectory.isEmpty())
        {
            m_bitmapDirectory = m_lbxDirectory;
        }
        listBitmapFiles(m_bitmapDirectory);
    }
}


void DialogLbxEditor::on_pushButton_Replace_clicked()
{
    int lbxIndex = ui->comboBox_LbxIndex->currentIndex();

    if ((lbxIndex < 0) || (lbxIndex >= m_lbxAnimations.count()) || (1 != m_lbxAnimations[lbxIndex].count()) || (1 != m_bitmapAnimation.count()))
    {
        (void)QMessageBox::warning(this,
            tr("Replace LBX"),
            tr("Please replace a single image.\n"
            "At this time replacing animations is not supported."));
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
