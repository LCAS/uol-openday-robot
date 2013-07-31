#include "rqt_openday_gui/openday_gui.h"

namespace rqt_openday_gui {
OpendayGui::OpendayGui() :rqt_gui_cpp::Plugin()
    , widget(0)
{
    setObjectName("Openday Gui");
    //Sets application to be full screen
    //this->setWindowState(Qt::WindowFullScreen);
}

void OpendayGui::initPlugin(qt_gui_cpp::PluginContext& context) {
    ROS_INFO("Init");
    
    // access standalone command line arguments
    QStringList argv = context.argv();
    // create QWidget
    widget = new QWidget();
    // extend the widget with all attributes and children from UI file
    ui.setupUi(widget);
	widget->setWindowState(Qt::WindowFullScreen);
	//widget->showFullScreen(); //doesn't work
    // add widget to the user interface
    context.addWidget(widget);
    
    //Setup service clients and subscribers
    //reset_client = getNodeHandle().serviceClient<scitos_msgs::ResetMotorStop>(RESET_MOTORS);
   // emergency_client = getNodeHandle().serviceClient<scitos_msgs::OpendayGui>(EMERGENCY_STOP);
	//sub = getNodeHandle().subscribe(BUMPER, 1000, &OpendayGui::bumperCallback, this);
    
    //connect Qt signals and slots
	connect(ui.Full_Screen_Logo, SIGNAL(clicked()), this, SLOT(on_Full_Screen_Logo_clicked()));
    connect(ui.Linda_Button, SIGNAL(clicked()), this, SLOT(on_Linda_Button_clicked()));
	connect(ui.SoCS_Button, SIGNAL(clicked()), this, SLOT(on_SoCS_Button_clicked()));
	connect(ui.University_Button, SIGNAL(clicked()), this, SLOT(on_University_Button_clicked()));
	connect(ui.Fun_Facts_Button, SIGNAL(clicked()), this, SLOT(on_Fun_Facts_Button_clicked()));
	connect(ui.Meet_The_Team_Button, SIGNAL(clicked()), this, SLOT(on_Meet_The_Team_Button_clicked()));
	connect(ui.Tour_Button, SIGNAL(clicked()), this, SLOT(on_Tour_Button_clicked()));
	connect(ui.Talking_Button, SIGNAL(clicked()), this, SLOT(on_Talking_Button_clicked()));
	connect(ui.Image_easterEgg, SIGNAL(clicked()), this, SLOT(on_Image_easterEgg_clicked()));
	connect(ui.Strands_Button, SIGNAL(clicked()), this, SLOT(on_Strands_Button_clicked()));
	connect(ui.Meet_The_Team_Back, SIGNAL(clicked()), this, SLOT(on_Meet_The_Team_Back_clicked()));
	connect(ui.Tour_Back, SIGNAL(clicked()), this, SLOT(on_Tour_Back_clicked()));
	connect(ui.Tour_Lab_C, SIGNAL(clicked()), this, SLOT(on_Tour_Lab_C_clicked()));
	connect(ui.Tour_Lift, SIGNAL(clicked()), this, SLOT(on_Tour_Lift_clicked()));
	connect(ui.Tour_Lab_A, SIGNAL(clicked()), this, SLOT(on_Tour_Lab_A_clicked()));
	connect(ui.Tour_Office, SIGNAL(clicked()), this, SLOT(on_Tour_Office_clicked()));
	connect(ui.Tour_Lab_B, SIGNAL(clicked()), this, SLOT(on_Tour_Lab_B_clicked()));
	connect(ui.Talk_Back, SIGNAL(clicked()), this, SLOT(on_Talk_Back_clicked()));
	connect(ui.hello_speak_button, SIGNAL(clicked()), this, SLOT(on_hello_speak_button_clicked()));
	connect(ui.colour_speak_button, SIGNAL(clicked()), this, SLOT(on_colour_speak_button_clicked()));
	connect(ui.welcome_speak_button, SIGNAL(clicked()), this, SLOT(on_welcome_speak_button_clicked()));
	connect(ui.goodday_speak_button, SIGNAL(clicked()), this, SLOT(on_goodday_speak_button_clicked()));
	connect(ui.september_speak_button, SIGNAL(clicked()), this, SLOT(on_september_speak_button_clicked()));
	connect(ui.zebadiah_speak_button, SIGNAL(clicked()), this, SLOT(on_zebadiah_speak_button_clicked()));
	connect(ui.lightbulb_speak_button, SIGNAL(clicked()), this, SLOT(on_lightbulb_speak_button_clicked()));
	connect(ui.Strands_Back, SIGNAL(clicked()), this, SLOT(on_Strands_Back_clicked()));
	connect(ui.Lab_Button, SIGNAL(clicked()), this, SLOT(on_Lab_Button_clicked()));
	connect(ui.Tutors_info, SIGNAL(clicked()), this, SLOT(on_Tutors_info_clicked()));
	connect(ui.Course_info, SIGNAL(clicked()), this, SLOT(on_Course_info_clicked()));
	connect(ui.course_Back, SIGNAL(clicked()), this, SLOT(on_course_Back_clicked()));
	connect(ui.Tutor_Back, SIGNAL(clicked()), this, SLOT(on_Tutor_Back_clicked()));
	connect(ui.David_Face, SIGNAL(clicked()), this, SLOT(on_David_Face_clicked()));
	connect(ui.Marc_Face, SIGNAL(clicked()), this, SLOT(on_Marc_Face_clicked()));
	connect(ui.John_Face, SIGNAL(clicked()), this, SLOT(on_John_Face_clicked()));
	connect(ui.Grzegorz_Face, SIGNAL(clicked()), this, SLOT(on_Grzegorz_Face_clicked()));
	connect(ui.Shigang_Face, SIGNAL(clicked()), this, SLOT(on_Shigang_Face_clicked()));
	connect(ui.Murray_Face, SIGNAL(clicked()), this, SLOT(on_Murray_Face_clicked()));
	connect(ui.Mark_Face, SIGNAL(clicked()), this, SLOT(on_Mark_Face_clicked()));
	connect(ui.Kevin_Face, SIGNAL(clicked()), this, SLOT(on_Kevin_Face_clicked()));
	connect(ui.Bashir_Face, SIGNAL(clicked()), this, SLOT(on_Bashir_Face_clicked()));
	connect(ui.Derek_Face, SIGNAL(clicked()), this, SLOT(on_Derek_Face_clicked()));
	connect(ui.Lab_Back, SIGNAL(clicked()), this, SLOT(on_Lab_Back_clicked()));
	connect(ui.Ranking_Button, SIGNAL(clicked()), this, SLOT(on_Ranking_Button_clicked()));
	connect(ui.Campus_Button, SIGNAL(clicked()), this, SLOT(on_Campus_Button_clicked()));
	connect(ui.City_button, SIGNAL(clicked()), this, SLOT(on_City_button_clicked()));
	connect(ui.VC_message_button, SIGNAL(clicked()), this, SLOT(on_VC_message_button_clicked()));
	connect(ui.campus_Back, SIGNAL(clicked()), this, SLOT(on_campus_Back_clicked()));
	connect(ui.Rank_Back, SIGNAL(clicked()), this, SLOT(on_Rank_Back_clicked()));
	connect(ui.City_Back, SIGNAL(clicked()), this, SLOT(on_City_Back_clicked()));
	connect(ui.VC_Back, SIGNAL(clicked()), this, SLOT(on_VC_Back_clicked()));
	connect(ui.Next_Fun_Fact, SIGNAL(clicked()), this, SLOT(on_Next_Fun_Fact_clicked()));
	connect(ui.Main_Menu_Button, SIGNAL(clicked()), this, SLOT(on_Main_Menu_Button_clicked()));
	connect(ui.Close_step1, SIGNAL(clicked()), this, SLOT(on_Close_step1_clicked()));
	connect(ui.close_step2, SIGNAL(clicked()), this, SLOT(on_close_step2_clicked()));
}

void OpendayGui::shutdownPlugin()
{
    //Shutdown subsriber and ros::spin
    //sub.shutdown();
}

void OpendayGui::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
{
  // No settings to save
}

void OpendayGui::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
{
  // No setting to restore
}


void OpendayGui::on_Linda_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pLinda);
}

void OpendayGui::on_Main_Menu_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pMainMenu);
}

void OpendayGui::on_SoCS_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pSoCS);
}

void OpendayGui::on_University_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pUniversity);
}

void OpendayGui::on_Fun_Facts_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pFunFacts);
}

void OpendayGui::on_Meet_The_Team_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pMeetTheTeam);
}

void OpendayGui::on_Tour_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pTour);
}

void OpendayGui::on_Talking_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pTalking);
}

void OpendayGui::on_hello_speak_button_clicked()
{
    // @TODO: ROS Talk to say -  "Hello! My Name Is Linda."
}

void OpendayGui::on_welcome_speak_button_clicked()
{
   // @TODO: ROS Talk to say - "Welcome to the school of computer Science."
}

void OpendayGui::on_goodday_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "We hope you have a plesent day today."
}

void OpendayGui::on_september_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "I look forward to seeing you in september."
}

void OpendayGui::on_zebadiah_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "I have a pet hamster named zebadiah."
}

void OpendayGui::on_lightbulb_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "How many humans does it take to screw in a light bulb?"
}

void OpendayGui::on_colour_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "My favourite colour is orange."
}

void OpendayGui::on_Tour_Lab_A_clicked()
{
    // @TODO: ROS Nav to go - "Comp Lab A"
}

void OpendayGui::on_Tour_Lab_B_clicked()
{
   // @TODO: ROS Nav to go - "Comp Lab B"
}

void OpendayGui::on_Tour_Lab_C_clicked()
{
    // @TODO: ROS Nav to go - "Comp Lab C"
}

void OpendayGui::on_Tour_Lift_clicked()
{
    // @TODO: ROS Nav to go - "Lift"
}

void OpendayGui::on_Tour_Office_clicked()
{
    // @TODO: ROS Nav to go - "Offices"
}

void OpendayGui::on_Course_info_clicked()
{
   ui.BasePanel->setCurrentIndex(pCourse);
}

void OpendayGui::on_Tutors_info_clicked()
{
    ui.BasePanel->setCurrentIndex(pTutors);
}

void OpendayGui::on_Close_step1_clicked()
{
    ui.close_step2->setEnabled(true);
}

void OpendayGui::on_David_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>David Cobham</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_Marc_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Marc Hanheide</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_Grzegorz_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Grzegorz Cielniak</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_John_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>John Lewak</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_Kevin_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Kevin Jacques</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_Mark_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Mark Doughty</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_Murray_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>John Murray</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_Shigang_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Shigang Yue</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_Bashir_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Bashir Al-Diri</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_Derek_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Derek Foster</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
}

void OpendayGui::on_Campus_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pCampus);
}

void OpendayGui::on_Ranking_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pRankings);
}

void OpendayGui::on_City_button_clicked()
{
    ui.BasePanel->setCurrentIndex(pCity);
}

void OpendayGui::on_VC_message_button_clicked()
{
    ui.BasePanel->setCurrentIndex(pMessage);
}

void OpendayGui::on_Lab_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pLabs);
}

void OpendayGui::on_Meet_The_Team_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pLinda);
}

void OpendayGui::on_Tour_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pLinda);
}

void OpendayGui::on_Talk_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pLinda);
}

void OpendayGui::on_course_Back_clicked()
{
        ui.BasePanel->setCurrentIndex(pSoCS);
}

void OpendayGui::on_Tutor_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pSoCS);
}

void OpendayGui::on_Lab_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pSoCS);
}

void OpendayGui::on_campus_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pUniversity);
}

void OpendayGui::on_Rank_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pUniversity);
}

void OpendayGui::on_City_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pUniversity);
}

void OpendayGui::on_VC_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pUniversity);
}

void OpendayGui::on_Next_Fun_Fact_clicked()
{
    if(ui.Fun_Facts_Stack->currentIndex()==3)
    {
        ui.Fun_Facts_Stack->setCurrentIndex(0);
    }else
    {
        ui.Fun_Facts_Stack->setCurrentIndex((ui.Fun_Facts_Stack->currentIndex()+1));
    }
}

void OpendayGui::on_Strands_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pStrands);
}

void OpendayGui::on_Strands_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pLinda);
}

void OpendayGui::on_Full_Screen_Logo_clicked()
{
//To Get Full Screen

}
}
PLUGINLIB_EXPORT_CLASS(rqt_openday_gui::OpendayGui, rqt_gui_cpp::Plugin)
