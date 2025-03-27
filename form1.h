/////////////////////////////////////////////////////////////////////////////
// Name:        form1.h
// Purpose:     
// Author:      TSN
// Modified by: 
// Created:     13/11/2023 10:18:57
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _FORM1_H_
#define _FORM1_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
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
#define ID_FORM1 10000
#define ID_TEXTCTRL_PASSWORD 10001
#define ID_BUTTON 10002
#define SYMBOL_FORM1_STYLE wxCAPTION|wxCLOSE_BOX
#define SYMBOL_FORM1_TITLE wxT("Авторизация")
#define SYMBOL_FORM1_IDNAME ID_FORM1
#define SYMBOL_FORM1_SIZE wxSize(200, 160)
#define SYMBOL_FORM1_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * Form1 class declaration
 */

class Form1: public wxFrame
{    
    DECLARE_CLASS( Form1 )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    Form1();
    Form1( wxWindow* parent, wxWindowID id = SYMBOL_FORM1_IDNAME, const wxString& caption = SYMBOL_FORM1_TITLE, const wxPoint& pos = SYMBOL_FORM1_POSITION, const wxSize& size = SYMBOL_FORM1_SIZE, long style = SYMBOL_FORM1_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_FORM1_IDNAME, const wxString& caption = SYMBOL_FORM1_TITLE, const wxPoint& pos = SYMBOL_FORM1_POSITION, const wxSize& size = SYMBOL_FORM1_SIZE, long style = SYMBOL_FORM1_STYLE );

    /// Destructor
    ~Form1();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin Form1 event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void OnNext( wxCommandEvent& event );

////@end Form1 event handler declarations

////@begin Form1 member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end Form1 member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin Form1 member variables
    wxTextCtrl* m_password;
////@end Form1 member variables
};

#endif
    // _FORM1_H_
