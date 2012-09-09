#ifndef DIALOGLBXEDITOR_H
#define DIALOGLBXEDITOR_H

#include <QDialog>
#include <QFileDialog>
class QAbstractButton;
class QGraphicsScene;
class QGraphicsView;

#include "MoMLbxBase.h"
#include "QMoMLbx.h"
#include "QMoMSharedPointers.h"

namespace Ui {
class DialogLbxEditor;
}

class DialogLbxEditor : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogLbxEditor(QWidget *parent = 0);
    ~DialogLbxEditor();

private:
    QString constructFrameFilename(const QString& bitmapFilename, int frameNr);
    void loadBitmap(const QString& filename);
    void loadLbx(const QString& filename);
    void updateBitmapImage(const QString& bitmapfilename);
    void updateImage(QGraphicsView* view, const MoM::QMoMAnimation& curAnimation, int line = 0, bool clearImage = true);
    void updateLbxImage(int lbxIndex);
    void listBitmapFiles(const QString& directory);

private slots:
    void on_comboBox_FileIndex_currentIndexChanged(const QString &arg1);
    void on_comboBox_LbxIndex_currentIndexChanged(int index);
    void on_pushButton_Load_clicked();
    void on_pushButton_Replace_clicked();

    void on_pushButton_SavePics_clicked();

private:
    Ui::DialogLbxEditor *ui;

private:
    QGraphicsScene* m_sceneBitmap;
    QGraphicsScene* m_sceneLbx;
    MoM::QMoMPalette m_colorTable;
    QString m_bitmapDirectory;
    QString m_lbxDirectory;
    QString m_bitmapFilename;
    QString m_lbxFilename;
    QFileDialog m_filedialogLoad;
    QFileDialog m_filedialogSave;
    MoM::MoMLbxBase m_lbx;
    QVector<MoM::QMoMAnimation> m_lbxAnimations;
    MoM::QMoMAnimation m_bitmapAnimation;
};


#endif // DIALOGLBXEDITOR_H
