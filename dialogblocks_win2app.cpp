/////////////////////////////////////////////////////////////////////////////
// Name:        dialogblocks_win2app.cpp
// Purpose:     
// Author:      TSN
// Modified by: 
// Created:     10/11/2023 18:42:07
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/wxprec.h"

////@begin includes
////@end includes

#include "dialogblocks_win2app.h"

////@begin XPM images
////@end XPM images


/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( DialogBlocks_win2App )
////@end implement app


/*
 * DialogBlocks_win2App type definition
 */

IMPLEMENT_CLASS( DialogBlocks_win2App, wxApp )


/*
 * DialogBlocks_win2App event table definition
 */

BEGIN_EVENT_TABLE( DialogBlocks_win2App, wxApp )

////@begin DialogBlocks_win2App event table entries
////@end DialogBlocks_win2App event table entries

END_EVENT_TABLE()


/*
 * Constructor for DialogBlocks_win2App
 */

DialogBlocks_win2App::DialogBlocks_win2App()
{
    Init();
}


/*
 * Member initialisation
 */

void DialogBlocks_win2App::Init()
{
////@begin DialogBlocks_win2App member initialisation
////@end DialogBlocks_win2App member initialisation
}

/*
 * Initialisation for DialogBlocks_win2App
 */

bool DialogBlocks_win2App::OnInit()
{    
////@begin DialogBlocks_win2App initialisation
	// Remove the comment markers above and below this block
	// to make permanent changes to the code.

#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	Form1* mainWindow = new Form1( NULL );
	mainWindow->Show(true);
////@end DialogBlocks_win2App initialisation

    return true;
}


/*
 * Cleanup for DialogBlocks_win2App
 */

int DialogBlocks_win2App::OnExit()
{    
////@begin DialogBlocks_win2App cleanup
	return wxApp::OnExit();
////@end DialogBlocks_win2App cleanup
}

