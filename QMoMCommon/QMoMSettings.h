#ifndef QMOMSETTINGS_H
#define QMOMSETTINGS_H

class QMoMSettings
{
public:
    /// \brief  Initializes the QSettings configuration
    /// \pre    The QApplication objects must have been created to
    ///         make sure the right directory is used.
    static void initialize(const QString& applicationName);

    /// \brief  Read and execute the common settings for a window
    static void readSettings(QWidget* window);

    /// \brief  Write the common settings for a window
    static void writeSettings(QWidget* window);

private:
    static void recurseRead(class QSettings& settings, QObject* object);
    static void recurseWrite(class QSettings& settings, QObject* object);
};

#endif // QMOMSETTINGS_H
