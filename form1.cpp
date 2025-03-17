/////////////////////////////////////////////////////////////////////////////
// Name:        form1.cpp
// Purpose:     
// Author:      TSN
// Modified by: 
// Created:     13/11/2023 10:18:57
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

////@begin includes
#include "form2.h"
////@end includes

#include "form1.h"

////@begin XPM images
#include "tsnsoft.xpm"
////@end XPM images


/*
 * Form1 type definition
 */

IMPLEMENT_CLASS(Form1, wxFrame)


/*
 * Form1 event table definition
 */

	BEGIN_EVENT_TABLE(Form1, wxFrame)

	////@begin Form1 event table entries
    EVT_BUTTON( ID_BUTTON, Form1::OnNext )
	////@end Form1 event table entries

	END_EVENT_TABLE()


	/*
	 * Form1 constructors
	 */

	Form1::Form1()
{
	Init();
}

Form1::Form1(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	Init();
	Create(parent, id, caption, pos, size, style);
}


/*
 * Form1 creator
 */

bool Form1::Create(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	////@begin Form1 creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    this->SetFont(wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Tahoma")));
    CreateControls();
    SetIcon(GetIconResource(wxT("tsnsoft.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
	////@end Form1 creation
	return true;
}


/*
 * Form1 destructor
 */

Form1::~Form1()
{
	////@begin Form1 destruction
	////@end Form1 destruction
}


/*
 * Member initialisation
 */

void Form1::Init()
{
	////@begin Form1 member initialisation
    dt = "???";
    m_password = NULL;
	////@end Form1 member initialisation
}


/*
 * Control creation for Form1
 */

void Form1::CreateControls()
{
	////@begin Form1 content construction
    Form1* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer1);

    wxStaticText* itemStaticText2 = new wxStaticText( itemFrame1, wxID_STATIC, wxT("Введите пароль:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText2->SetForegroundColour(wxColour(255, 0, 0));
    itemStaticText2->SetFont(wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Tahoma")));
    itemBoxSizer1->Add(itemStaticText2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_password = new wxTextCtrl( itemFrame1, ID_TEXTCTRL_PASSWORD, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
    m_password->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Tahoma")));
    itemBoxSizer1->Add(m_password, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton1 = new wxButton( itemFrame1, ID_BUTTON, wxT("Войти"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton1->SetDefault();
    itemBoxSizer1->Add(itemButton1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

	////@end Form1 content construction
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void Form1::OnNext(wxCommandEvent& event)
{
	dt = m_password->GetValue(); // Запись в открытую переменную
	if (dt != "TSN") {
		wxMessageBox(wxT("Введите правильное имя: TSN !"), wxT("Ошибка"), wxOK | wxICON_ERROR);
		return;
	}
	Form2* window = new Form2(this); // Создание окна 2
	window->Show(true); // Показ окна 2
	Hide(); // Скрытие родительского окна
}


/*
 * Should we show tooltips?
 */

bool Form1::ShowToolTips()
{
	return true;
}

/*
 * Get bitmap resources
 */

wxBitmap Form1::GetBitmapResource(const wxString& name)
{
	// Bitmap retrieval
////@begin Form1 bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
	////@end Form1 bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon Form1::GetIconResource(const wxString& name)
{
	// Icon retrieval
////@begin Form1 icon retrieval
    wxUnusedVar(name);
    if (name == wxT("tsnsoft.xpm"))
    {
        wxIcon icon(tsnsoft_xpm);
        return icon;
    }
    return wxNullIcon;
	////@end Form1 icon retrieval
}
