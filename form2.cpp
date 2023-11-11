/////////////////////////////////////////////////////////////////////////////
// Name:        form2.cpp
// Purpose:     
// Author:      TSN
// Modified by: 
// Created:     10/11/2023 18:57:38
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
////@end includes

#include "form2.h"
#include "form1.h"

////@begin XPM images
////@end XPM images


/*
 * Form2 type definition
 */

IMPLEMENT_CLASS(Form2, wxFrame)


/*
 * Form2 event table definition
 */

	BEGIN_EVENT_TABLE(Form2, wxFrame)

	////@begin Form2 event table entries
    EVT_CLOSE( Form2::OnCloseWindow )
    EVT_BUTTON( ID_BUTTON_NEXT, Form2::OnBack )
    EVT_BUTTON( ID_BUTTON_EXIT, Form2::OnExit )
	////@end Form2 event table entries

	EVT_SHOW(Form2::OnShow) // Событие показа окна (САМИ ДОБАВИЛИ БЕЗ КОНСТРУКТОРА)

	END_EVENT_TABLE()


	/*
	 * Form2 constructors
	 */

	Form2::Form2()
{
	Init();
}

Form2::Form2(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	Init();
	Create(parent, id, caption, pos, size, style);
}


/*
 * Form2 creator
 */

bool Form2::Create(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
	////@begin Form2 creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("MAIN_ICON")));
    Centre();
	////@end Form2 creation
	return true;
}


/*
 * Form2 destructor
 */

Form2::~Form2()
{
	////@begin Form2 destruction
	////@end Form2 destruction
}


/*
 * Member initialisation
 */

void Form2::Init()
{
	////@begin Form2 member initialisation
	////@end Form2 member initialisation
}


/*
 * Control creation for Form2
 */

void Form2::CreateControls()
{
	////@begin Form2 content construction
    Form2* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer1 = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(itemBoxSizer1);

    wxStaticText* itemStaticText1 = new wxStaticText( itemFrame1, wxID_STATIC_PASSWORD, _("Password"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
    itemStaticText1->SetForegroundColour(wxColour(251, 248, 206));
    itemStaticText1->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Tahoma")));
    itemBoxSizer1->Add(itemStaticText1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticBitmap* itemStaticBitmap1 = new wxStaticBitmap( itemFrame1, wxID_STATIC, itemFrame1->GetBitmapResource(wxT("WX")), wxDefaultPosition, wxSize(292, 226), 0 );
    itemBoxSizer1->Add(itemStaticBitmap1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer1->Add(itemBoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton3 = new wxButton( itemFrame1, ID_BUTTON_NEXT, wxGetTranslation(wxString() + (wxChar) 0x041D + (wxChar) 0x0430 + (wxChar) 0x0437 + (wxChar) 0x0430 + (wxChar) 0x0434), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemButton3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer2->Add(150, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton5 = new wxButton( itemFrame1, ID_BUTTON_EXIT, wxGetTranslation(wxString() + (wxChar) 0x0412 + (wxChar) 0x044B + (wxChar) 0x0445 + (wxChar) 0x043E + (wxChar) 0x0434), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton5->SetDefault();
    itemBoxSizer2->Add(itemButton5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	////@end Form2 content construction
}


/*
 * Should we show tooltips?
 */

bool Form2::ShowToolTips()
{
	return true;
}

/*
 * Get bitmap resources
 */

wxBitmap Form2::GetBitmapResource(const wxString& name)
{
	// Bitmap retrieval
////@begin Form2 bitmap retrieval
    wxUnusedVar(name);
    if (name == wxT("WX"))
    {
        wxBitmap bitmap(wxT("WX"), wxBITMAP_TYPE_BMP_RESOURCE);
        return bitmap;
    }
    return wxNullBitmap;
	////@end Form2 bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon Form2::GetIconResource(const wxString& name)
{
	// Icon retrieval
////@begin Form2 icon retrieval
    wxUnusedVar(name);
    if (name == wxT("MAIN_ICON"))
    {
        wxIcon icon(wxT("MAIN_ICON"), wxBITMAP_TYPE_ICO_RESOURCE);
        return icon;
    }
    return wxNullIcon;
	////@end Form2 icon retrieval
}


// Событие показа окна (САМИ СЮДА ДОБАВИЛИ, НЕ КОНСТРУКТОР)
void Form2::OnShow(wxShowEvent& event)
{
	wxWindow* window = this; // Получение указателя на текущее окно
	Form1* mainWindow = (Form1*)window->GetParent(); // Получение указателя на родительское окно
	wxString ss = mainWindow->GetDt(); // Получение значения переменной из родительского окна
	((wxStaticText*)FindWindow(wxID_STATIC_PASSWORD))->SetLabel(ss); // Установка значения переменной в текстовое поле
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
 */

// Кнопка назад
void Form2::OnBack(wxCommandEvent& event)
{
	Destroy(); // Уничтожение окна
	this->GetParent()->Show(true); // Показ родительского основного окна
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

// Кнопка выхода
void Form2::OnExit(wxCommandEvent& event)
{
    wxWindow* window = this; // Получение указателя на текущее окно
    window->Destroy(); // Уничтожение окна
    this->GetParent()->Destroy(); // Уничтожение родительского основного окна (закрытие программы)

}


/*
 * wxEVT_CLOSE_WINDOW event handler for ID_FORM2
 */

// Закрытие окна
void Form2::OnCloseWindow(wxCloseEvent& event)
{
	wxWindow* window = this; // Получение указателя на текущее окно
	window->Destroy(); // Уничтожение окна
	this->GetParent()->Destroy(); // Уничтожение родительского основного окна (закрытие программы)
}

