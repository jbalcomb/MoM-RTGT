#ifndef MOMHOOKMANAGER_H
#define MOMHOOKMANAGER_H

namespace MoM {

class MoMGameBase;
class MoMProcess;

class MoMHookManager
{
public:
    explicit MoMHookManager(MoMGameBase* game);

    /// Write the hook code into WIZARDS.EXE
    bool insertHook();

    /// Restore the original code in WIZARDS.EXE
    /// NOT IMPLEMENTED
    void removeHook();

    /// Make MoM stop when it encounters the hook.
    bool raiseHook();

    /// Make MoM ignore the hook.
    bool retractHook();

    /// Wait for MoM to trigger the hook.
    /// \retval true if the hook was triggered
    /// \retval false if the connection is broken or a timeout occurred
    bool waitForHook(double timeout);

    /// Let MoM continue from the hook.
    bool releaseHook();

private:
    MoMGameBase* m_game;
    MoMProcess*  m_process;
};

}

#endif // MOMHOOKMANAGER_H
