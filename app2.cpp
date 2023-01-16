#include <wx/wx.h>
#include <wx/wxprec.h>

class App2 : public wxApp
{

public:
    bool OnInit();
};

class Frame2 : public wxFrame
{
public:
    Frame2(const wxString &title, const wxPoint &pos, const wxSize &size);
    void onButtonClicked(wxCommandEvent &evt);
    void onSliderChanged(wxCommandEvent &evt);
    void onRadioChanged(wxCommandEvent &evt);
    void onListBoxChanged(wxCommandEvent &evt);
    wxDECLARE_EVENT_TABLE();
};

enum ComponentIDs
{
    BUTTON_ID = 1,
    LISTBOX_ID = 2,
    RADIO_ID = 3,
    SLIDER_ID = 4
};

wxBEGIN_EVENT_TABLE(Frame2, wxFrame)                  //
    EVT_BUTTON(BUTTON_ID, Frame2::onButtonClicked)    //
    EVT_LISTBOX(LISTBOX_ID, Frame2::onListBoxChanged) //
    EVT_RADIOBOX(RADIO_ID, Frame2::onRadioChanged)    //
    EVT_SLIDER(SLIDER_ID, Frame2::onSliderChanged)    //
    wxEND_EVENT_TABLE()                               //

    Frame2::Frame2(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxPanel *panel = new wxPanel(this, wxID_ANY, wxPoint(10, 0), wxSize(800, 600));
    wxButton *button = new wxButton(panel, BUTTON_ID, wxString("Button1"), wxPoint(10, 50), wxSize(150, 50));
    wxArrayString choices;
    choices.Add("Line 1");
    choices.Add("Line 2");
    choices.Add("Line 3");

    wxListBox *listBox = new wxListBox(panel, LISTBOX_ID, wxPoint(10, 100), wxSize(150, 50), choices);
    wxRadioBox *radioBox = new wxRadioBox(panel, RADIO_ID, "Radio", wxPoint(10, 200), wxSize(250, 50), choices);
    wxGauge *gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(10, 250), wxSize(150, 50), wxGA_PROGRESS);
    gauge->SetValue(25);

    wxSlider *slider = new wxSlider(panel, SLIDER_ID, 10, 0, 100, wxPoint(10, 250), wxSize(150, 50), wxSL_HORIZONTAL);
    slider->SetValue(25);

    CreateStatusBar();
};

bool App2::OnInit()
{
    Frame2 *frame2 = new Frame2("I'm Frame2", wxPoint(150, 150), wxSize(800, 600));
    frame2->Show(true);

    return true;
};

wxIMPLEMENT_APP(App2);

void Frame2::onButtonClicked(wxCommandEvent &evt)
{
    wxLogStatus("Button clicked");
};

void Frame2::onSliderChanged(wxCommandEvent &evt)
{
    wxString string = wxString::Format("Slider %d", evt.GetInt());
    wxLogStatus(string);
};

void Frame2::onRadioChanged(wxCommandEvent &evt)
{
    wxString string = wxString::Format("Radio %d", evt.GetInt());
    wxLogStatus(string);
};

void Frame2::onListBoxChanged(wxCommandEvent &evt)
{
    wxString string = wxString::Format("ListBox %d", evt.GetInt());
    wxLogStatus(string);
};