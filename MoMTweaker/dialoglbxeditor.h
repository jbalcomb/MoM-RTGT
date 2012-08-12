#ifndef DIALOGLBXEDITOR_H
#define DIALOGLBXEDITOR_H

#include <QDialog>
#include <QFileDialog>
class QAbstractButton;
class QGraphicsScene;
class QGraphicsView;

#include "MoMLbxBase.h"
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
    typedef QVector<QMoMImagePtr> Animation;

    void loadBitmap(const QString& filename);
    void loadLbx(const QString& filename);
    void updateBitmapImage(const QString& bitmapfilename);
    void updateImage(QGraphicsView* view, const Animation& curAnimation);
    void updateLbxImage(int lbxIndex);
    void listBitmapFiles(const QString& directory);

private slots:
    void on_comboBox_FileIndex_currentIndexChanged(const QString &arg1);
    void on_comboBox_LbxIndex_currentIndexChanged(int index);
    void on_pushButton_Load_clicked();
    void on_pushButton_Replace_clicked();

private:
    Ui::DialogLbxEditor *ui;

private:
    QGraphicsScene* m_sceneBitmap;
    QGraphicsScene* m_sceneLbx;
    QVector<QRgb> m_colorTable;
    QString m_bitmapDirectory;
    QString m_lbxDirectory;
    QString m_bitmapFilename;
    QString m_lbxFilename;
    QFileDialog m_filedialogLoad;
    MoM::MoMLbxBase m_lbx;
    QVector<Animation> m_lbxAnimations;
    Animation m_bitmapAnimation;
};


#endif // DIALOGLBXEDITOR_H
