﻿/////////////////////////////////////////////////////////////////////////////
// Name:        form2.cpp
// Purpose:     
// Author:      TSN
// Modified by: 
// Created:     13/11/2023 10:19:03
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
#include "tsnsoft.xpm"
#include "wxwidgets.xpm"
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
    SetIcon(GetIconResource(wxT("tsnsoft.xpm")));
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
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
    _password = NULL;
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

    _password = new wxStaticText( itemFrame1, wxID_STATIC_PASSWORD, wxT("Password"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
    _password->SetForegroundColour(wxColour(255, 0, 0));
    _password->SetFont(wxFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Tahoma")));
    itemBoxSizer1->Add(_password, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticBitmap* itemStaticBitmap1 = new wxStaticBitmap( itemFrame1, wxID_STATIC, itemFrame1->GetBitmapResource(wxT("wxwidgets.xpm")), wxDefaultPosition, wxSize(292, 226), 0 );
    itemBoxSizer1->Add(itemStaticBitmap1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer1->Add(itemBoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton3 = new wxButton( itemFrame1, ID_BUTTON_NEXT, wxT("Назад"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemButton3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer2->Add(150, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton5 = new wxButton( itemFrame1, ID_BUTTON_EXIT, wxT("Выход"), wxDefaultPosition, wxDefaultSize, 0 );
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
    if (name == wxT("wxwidgets.xpm"))
    {
        wxBitmap bitmap(wxwidgets_xpm);
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
    if (name == wxT("tsnsoft.xpm"))
    {
        wxIcon icon(tsnsoft_xpm);
        return icon;
    }
    return wxNullIcon;
	////@end Form2 icon retrieval
}


// Событие показа окна (САМИ СЮДА ДОБАВИЛИ, НЕ КОНСТРУКТОР)
void Form2::OnShow(wxShowEvent& event)
{
   wxString ss = wxGetApp().GetDt(); // Чтение значения из глобальной открытой переменной dt через метод GetDt()
   _password->SetLabel(ss); // Установка значения глобальной переменной в текстовое поле
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
 */

 // Кнопка назад
void Form2::OnBack(wxCommandEvent& event)
{
    wxWindow* parent = this -> GetParent();  // Сохраняем указатель на родителя
    this -> Destroy();  // Уничтожаем текущее окно
    parent -> Show(true); // Показываем 1 окно
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

 // Кнопка выхода
void Form2::OnExit(wxCommandEvent& event)
{
    wxTheApp->Exit(); // Закрываем приложение
}


/*
 * wxEVT_CLOSE_WINDOW event handler for ID_FORM2
 */

 // Закрытие окна
void Form2::OnCloseWindow(wxCloseEvent& event)
{
    wxWindow* parent = this -> GetParent();  // Сохраняем указатель на родителя
    this -> Destroy();  // Уничтожаем текущее окно
    parent -> Show(true); // Показываем 1 окно
}

