/////////////////////////////////////////////////////////////////////////////
// Name:        form1.cpp
// Purpose:     
// Author:      TSN
// Modified by: 
// Created:     10/11/2023 18:42:20
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
    SetIcon(GetIconResource(wxT("MAIN_ICON")));
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

    wxStaticText* itemStaticText2 = new wxStaticText( itemFrame1, wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x0412 + (wxChar) 0x0432 + (wxChar) 0x0435 + (wxChar) 0x0434 + (wxChar) 0x0438 + (wxChar) 0x0442 + (wxChar) 0x0435 + wxT(" ") + (wxChar) 0x043F + (wxChar) 0x0430 + (wxChar) 0x0440 + (wxChar) 0x043E + (wxChar) 0x043B + (wxChar) 0x044C + wxT(":")), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText2->SetForegroundColour(wxColour(255, 0, 0));
    itemStaticText2->SetFont(wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Tahoma")));
    itemBoxSizer1->Add(itemStaticText2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl3 = new wxTextCtrl( itemFrame1, ID_TEXTCTRL_PASSWORD, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
    itemTextCtrl3->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Tahoma")));
    itemBoxSizer1->Add(itemTextCtrl3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton1 = new wxButton( itemFrame1, ID_BUTTON, wxGetTranslation(wxString() + (wxChar) 0x0412 + (wxChar) 0x043E + (wxChar) 0x0439 + (wxChar) 0x0442 + (wxChar) 0x0438), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton1->SetDefault();
    itemBoxSizer1->Add(itemButton1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

	////@end Form1 content construction
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
    if (name == wxT("MAIN_ICON"))
    {
        wxIcon icon(wxT("MAIN_ICON"), wxBITMAP_TYPE_ICO_RESOURCE);
        return icon;
    }
    return wxNullIcon;
	////@end Form1 icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

// Кнопка входа
void Form1::OnNext(wxCommandEvent& event)
{
	dt = ((wxTextCtrl*)FindWindow(ID_TEXTCTRL_PASSWORD))->GetValue(); // Запись в открытую переменную

	if (dt != "ТСН") {
		wxMessageBox("Введите правильное имя: ТСН !", "Ошибка", wxOK | wxICON_ERROR);
		return;
	}
	Form2* window = new Form2(this); // Создание окна 2
	window->Show(true); // Показ окна 2
	Hide(); // Скрытие родительского окна
}

