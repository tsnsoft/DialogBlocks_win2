/////////////////////////////////////////////////////////////////////////////
// Name:        dialogblocks_win2app.h
// Purpose:     
// Author:      TSN
// Modified by: 
// Created:     10/11/2023 18:42:07
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DIALOGBLOCKS_WIN2APP_H_
#define _DIALOGBLOCKS_WIN2APP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "form1.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * DialogBlocks_win2App class declaration
 */

class DialogBlocks_win2App: public wxApp
{    
    DECLARE_CLASS( DialogBlocks_win2App )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    DialogBlocks_win2App();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin DialogBlocks_win2App event handler declarations

////@end DialogBlocks_win2App event handler declarations

////@begin DialogBlocks_win2App member function declarations

////@end DialogBlocks_win2App member function declarations

////@begin DialogBlocks_win2App member variables
////@end DialogBlocks_win2App member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(DialogBlocks_win2App)
////@end declare app

#endif
    // _DIALOGBLOCKS_WIN2APP_H_
