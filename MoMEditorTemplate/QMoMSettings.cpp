#include <QCheckBox>
#include <QComboBox>
#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QSlider>
#include <QWidget>

#include <iostream>

#include "QMoMSettings.h"

QMoMSettings::QMoMSettings()
{
}

void QMoMSettings::initialize(const QString &applicationName)
{
    // Settings for the configuration
    QCoreApplication::setOrganizationName("MoMRTGT");
    QCoreApplication::setOrganizationDomain("sourceforge.net/projects/momrtgt/");
    QCoreApplication::setApplicationName(applicationName);
    QSettings::setDefaultFormat(QSettings::IniFormat);

    std::cout << "Using ini file in '" << QCoreApplication::applicationDirPath().toAscii().data() << "'" << std::endl;
    QSettings::setPath(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::applicationDirPath());
    QSettings::setPath(QSettings::IniFormat, QSettings::SystemScope, QCoreApplication::applicationDirPath());
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
    settings.setValue("size", window->size());
    settings.setValue("pos", window->pos());
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
    QComboBox* combobox =  dynamic_cast<QComboBox*>(object);
    if (0 != combobox)
    {
        combobox->setCurrentIndex(settings.value(combobox->objectName()).toInt());
    }
    QSlider* slider =  dynamic_cast<QSlider*>(object);
    if (0 != slider)
    {
        slider->setValue(settings.value(slider->objectName()).toInt());
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
    QSlider* slider =  dynamic_cast<QSlider*>(object);
    if (0 != slider)
    {
        settings.setValue(slider->objectName(), slider->value());
    }
    QComboBox* combobox =  dynamic_cast<QComboBox*>(object);
    if (0 != combobox)
    {
        settings.setValue(combobox->objectName(), combobox->currentIndex());
    }

    foreach(QObject* child, object->children())
    {
        recurseWrite(settings, child);
    }
}
