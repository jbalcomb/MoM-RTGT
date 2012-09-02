#ifndef MOMCORE_H
#define MOMCORE_H

namespace MoM {
    class MoMGameBase;
}

/// Keeps track of connected game
extern MoM::MoMGameBase* gGame;

MoM::MoMGameBase* connectToMoM();

//class PythonInterface
//{
//public:
//    connect();
//    Hook insertHook(exe_location, replacement_code);
//    removeHook(hook);
//    raiseHook(hook, python_function);
//    waitForHook(hook);
//    releaseHook(hook);
//private:
//    hooks;
//};

#endif // MOMCORE_H
