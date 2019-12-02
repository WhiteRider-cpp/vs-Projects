///////////////////////////////////////////////////////////////////////////////
// Log.h
// =====
// It prints out any log messages to file or dialog box.
// Log class is a singleton class which is contructed by calling
// Log::getInstance() (lazy initialization), and is destructed automatically
// when the application is terminated.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LOG_H
#define LOG_H

#include <string>
#include <fstream>
#include <windows.h>

#include "stdtfx.h"


    enum { LOG_MODE_FILE = 0, LOG_MODE_DIALOG, LOG_MODE_BOTH }; // log output selection
    enum { LOG_MAX_STRING = 1024 };

    // Clients are actually use this functions to send log messages.
    // USAGE: Win::log("I am the number %d.", 1);
    ExportedByUtil void Tracelog(const std::wstring& str);
    ExportedByUtil void Tracelog(const wchar_t *format, ...);
    ExportedByUtil void Tracelog(const char *format, ...);
    extern void logMode(int mode);



    // singleton class ////////////////////////////////////////////////////////
    class ExportedByUtil Log
    {
    public:
        ~Log();

        static Log& getInstance();              // return reference to this class object

        void setMode(int mode);                 // set log target: file or dialog
        void put(const std::wstring& str);      // print log message

    private:
        Log();                                  // hide it here to prevent instantiating this class
        Log(const Log& rhs);                    // must no body for copy ctor, so this class cannot have copy ctor

        const std::wstring getTime();           // return system time as string
        const std::wstring getDate();           // return system date as string

        int logMode;                            // file, dialog or both
        std::wofstream logFile;                 // log file handle
        HWND dialogHandle;                      // handle to dialog window
        HWND listHandle;                        // handle to listbox
    };
    ///////////////////////////////////////////////////////////////////////////

#endif

