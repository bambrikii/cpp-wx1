#include <wx/wx.h>

class App3 : public wxApp
{

public:
    bool OnInit();
};

class Frame3 : public wxFrame
{
private:
    wxGauge *gauge;

public:
    Frame3(const wxString &title, const wxPoint &pos, const wxSize &size);
    void onButtonClicked(wxCommandEvent &evt);
    void onSliderChanged(wxCommandEvent &evt);
    void onRadioChanged(wxCommandEvent &evt);
    void onListBoxChanged(wxCommandEvent &evt);
};

Frame3::Frame3(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxPanel *panel = new wxPanel(this, wxID_ANY, wxPoint(10, 0), wxSize(800, 600));
    wxButton *button = new wxButton(panel, wxID_ANY, wxString("Button1"), wxPoint(10, 50), wxSize(150, 50));
    wxArrayString choices;
    choices.Add("Line 1");
    choices.Add("Line 2");
    choices.Add("Line 3");

    wxListBox *listBox = new wxListBox(panel, wxID_ANY, wxPoint(10, 100), wxSize(150, 50), choices);
    wxRadioBox *radioBox = new wxRadioBox(panel, wxID_ANY, "Radio", wxPoint(10, 200), wxSize(250, 50), choices);
    wxGauge *gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(10, 250), wxSize(150, 50), wxGA_PROGRESS);
    gauge->SetValue(25);

    wxSlider *slider = new wxSlider(panel, wxID_ANY, 10, 0, 100, wxPoint(10, 250), wxSize(150, 50), wxSL_HORIZONTAL);
    slider->SetValue(25);
    this->gauge = gauge;

    CreateStatusBar();

    button->Bind(wxEVT_BUTTON, &Frame3::onButtonClicked, this);
    listBox->Bind(wxEVT_LISTBOX, &Frame3::onListBoxChanged, this);
    radioBox->Bind(wxEVT_RADIOBOX, &Frame3::onRadioChanged, this);
    slider->Bind(wxEVT_SLIDER, &Frame3::onSliderChanged, this);
    // auto lambda = [&](wxCommandEvent &evt)
    // { slider->SetValue(evt.GetInt()); };
    // slider->Bind(wxEVT_SLIDER, &lambda, this);
};

bool App3::OnInit()
{
    Frame3 *frame3 = new Frame3("I'm Frame3", wxPoint(150, 150), wxSize(800, 600));
    frame3->Show(true);

    return true;
};

wxIMPLEMENT_APP(App3);

void Frame3::onButtonClicked(wxCommandEvent &evt)
{
    wxLogStatus("Button clicked");
};

void Frame3::onSliderChanged(wxCommandEvent &evt)
{
    int val = evt.GetInt();
    wxString string = wxString::Format("Slider %d", val);
    wxLogStatus(string);
    gauge->SetValue(val);
};

void Frame3::onRadioChanged(wxCommandEvent &evt)
{
    wxString string = wxString::Format("Radio %d", evt.GetInt());
    wxLogStatus(string);
};

void Frame3::onListBoxChanged(wxCommandEvent &evt)
{
    wxString string = wxString::Format("ListBox %d", evt.GetInt());
    wxLogStatus(string);
};