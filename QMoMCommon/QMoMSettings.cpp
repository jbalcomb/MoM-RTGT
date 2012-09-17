#include <QCheckBox>
#include <QComboBox>
#include <QCoreApplication>
#include <QDebug>
#include <QFileDialog>
#include <QSettings>
#include <QSlider>
#include <QSplitter>
#include <QTableWidget>
#include <QTreeWidget>
#include <QWidget>

#include <iostream>

#include "QMoMSettings.h"

// TODO:
// - Save/restore directories of the file dialogs
// - Save/restore splitter positions
// - Save/restore column widths of tree view and table view
// - Set font??

void QMoMSettings::initialize(const QString &applicationName)
{
    // Settings for the configuration
    QCoreApplication::setOrganizationName("MoMRTGT");
    QCoreApplication::setOrganizationDomain("sourceforge.net/projects/momrtgt/");
    QCoreApplication::setApplicationName(applicationName);
}

void QMoMSettings::readSettings(QWidget* window)
{
    QSettings settings;

    settings.beginGroup(window->objectName());
    QVariant value = settings.value("pos");
    if (!value.isNull())
    {
        window->move(settings.value("pos").toPoint());
        window->resize(settings.value("size").toSize());
        recurseRead(settings, window);
    }
    settings.endGroup();
}

void QMoMSettings::writeSettings(QWidget* window)
{
    QSettings settings;

    settings.beginGroup(window->objectName());
    settings.setValue("pos", window->pos());
    settings.setValue("size", window->size());
    recurseWrite(settings, window);
    settings.endGroup();
}

void QMoMSettings::recurseRead(QSettings& settings, QObject* object)
{
    QCheckBox* checkbox = dynamic_cast<QCheckBox*>(object);
    if (0 != checkbox)
    {
        checkbox->setChecked(settings.value(checkbox->objectName()).toBool());
    }
    QComboBox* combobox = dynamic_cast<QComboBox*>(object);
    if (0 != combobox)
    {
        combobox->setCurrentIndex(settings.value(combobox->objectName()).toInt());
    }
    QFileDialog* filedialog = dynamic_cast<QFileDialog*>(object);
    if (0 != filedialog)
    {
        qDebug() << "QFileDialog" << filedialog->directory().absolutePath();
        filedialog->setDirectory(settings.value(filedialog->objectName()).toString());
        // Do not recurse
        return;
    }
    QSlider* slider = dynamic_cast<QSlider*>(object);
    if (0 != slider)
    {
        slider->setValue(settings.value(slider->objectName()).toInt());
    }
    QSplitter* splitter = dynamic_cast<QSplitter*>(object);
    if (0 != splitter)
    {
        splitter->restoreState(settings.value(splitter->objectName()).toByteArray());
    }
    QTableWidget* tablewidget = dynamic_cast<QTableWidget*>(object);
    if (0 != tablewidget)
    {
        tablewidget->restoreGeometry(settings.value(tablewidget->objectName()).toByteArray());
        // Do not recurse
        return;
    }
    QTreeWidget* treewidget = dynamic_cast<QTreeWidget*>(object);
    if (0 != treewidget)
    {
        QStringList columns = settings.value(treewidget->objectName()).toString().split(",");
        for (int i = 0; (i < treewidget->columnCount()) && (i < columns.count()); ++i)
        {
            treewidget->setColumnWidth(i, columns.at(i).toInt());
        }
        // Do not recurse
        return;
    }

    foreach(QObject* child, object->children())
    {
        recurseRead(settings, child);
    }
}

void QMoMSettings::recurseWrite(QSettings& settings, QObject* object)
{
    QCheckBox* checkbox = dynamic_cast<QCheckBox*>(object);
    if (0 != checkbox)
    {
        settings.setValue(checkbox->objectName(), checkbox->isChecked());
    }
    QComboBox* combobox = dynamic_cast<QComboBox*>(object);
    if (0 != combobox)
    {
        settings.setValue(combobox->objectName(), combobox->currentIndex());
    }
    QFileDialog* filedialog = dynamic_cast<QFileDialog*>(object);
    if (0 != filedialog)
    {
        qDebug() << "QFileDialog" << filedialog->directory().absolutePath();
        settings.setValue(filedialog->objectName(), filedialog->directory().absolutePath());
        // Do not recurse
        return;
    }
    QSlider* slider = dynamic_cast<QSlider*>(object);
    if (0 != slider)
    {
        settings.setValue(slider->objectName(), slider->value());
    }
    QSplitter* splitter = dynamic_cast<QSplitter*>(object);
    if (0 != splitter)
    {
        settings.setValue(splitter->objectName(), splitter->saveState());
    }
    QTableWidget* tablewidget = dynamic_cast<QTableWidget*>(object);
    if (0 != tablewidget)
    {
        settings.setValue(tablewidget->objectName(), tablewidget->saveGeometry());
        // Do not recurse
        return;
    }
    QTreeWidget* treewidget = dynamic_cast<QTreeWidget*>(object);
    if (0 != treewidget)
    {
        QStringList columns;
        for (int i = 0; i < treewidget->columnCount(); ++i)
        {
            columns << QString("%0").arg(treewidget->columnWidth(i));
        }
        settings.setValue(treewidget->objectName(), columns.join(","));
        // Do not recurse
        return;
    }

    foreach(QObject* child, object->children())
    {
        recurseWrite(settings, child);
    }
}
