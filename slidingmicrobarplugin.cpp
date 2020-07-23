#include "slidingmicrobar.h"
#include "slidingmicrobarplugin.h"

#include <QtPlugin>

SlidingMicroBarPlugin::SlidingMicroBarPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SlidingMicroBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool SlidingMicroBarPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SlidingMicroBarPlugin::createWidget(QWidget *parent)
{
    return new SlidingMicroBar(parent);
}

QString SlidingMicroBarPlugin::name() const
{
    return QLatin1String("SlidingMicroBar");
}

QString SlidingMicroBarPlugin::group() const
{
    return QLatin1String("");
}

QIcon SlidingMicroBarPlugin::icon() const
{
    return QIcon();
}

QString SlidingMicroBarPlugin::toolTip() const
{
    return QLatin1String("");
}

QString SlidingMicroBarPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool SlidingMicroBarPlugin::isContainer() const
{
    return false;
}

QString SlidingMicroBarPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SlidingMicroBar\" name=\"slidingMicroBar\">\n</widget>\n");
}

QString SlidingMicroBarPlugin::includeFile() const
{
    return QLatin1String("slidingmicrobar.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(slidingmicrobarplugin, SlidingMicroBarPlugin)
#endif // QT_VERSION < 0x050000
