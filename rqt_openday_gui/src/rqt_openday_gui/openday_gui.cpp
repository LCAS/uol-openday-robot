#include "rqt_openday_gui/openday_gui.h"

namespace rqt_openday_gui {
OpendayGui::OpendayGui() : rqt_gui_cpp::Plugin()
    , widget(0), ac("speak", true)
{
    setObjectName("Openday Gui");





  // create the action client
  // true causes the client to spin its own thread
	

}

void OpendayGui::initPlugin(qt_gui_cpp::PluginContext& context) {
    ROS_INFO("Init");
    
    // access standalone command line arguments
    QStringList argv = context.argv();
    // create QWidget
    widget = new QWidget();
    // extend the widget with all attributes and children from UI file
    ui.setupUi(widget);
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
	Mary_say("What would you like to know about me?");
}

void OpendayGui::on_Main_Menu_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pMainMenu);
}

void OpendayGui::on_SoCS_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pSoCS);
	Mary_say("Find out more about my home, the School of Computer Science.");
}

void OpendayGui::on_University_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pUniversity);
	Mary_say("Let me tell you more about my wonderful university");
}

void OpendayGui::on_Fun_Facts_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pFunFacts);
	Mary_say("Would you like to know something interesting about Lincoln University?");
}

void OpendayGui::on_Meet_The_Team_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pMeetTheTeam);
	Mary_say("Meet my parents, all 20 of them");
}

void OpendayGui::on_Tour_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pTour);
	Mary_say("Let me give you a tour");
}

void OpendayGui::on_Talking_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pTalking);
	Mary_say("Would you like me to say something?");
}

void OpendayGui::on_hello_speak_button_clicked()
{
    // @TODO: ROS Talk to say -  "Hello! My Name Is Linda."
		Mary_say("Hello! My Name Is Linda.");
}

void OpendayGui::on_welcome_speak_button_clicked()
{
   // @TODO: ROS Talk to say - "Welcome to the school of computer Science."
	Mary_say("Welcome to the school of computer Science.");
}

void OpendayGui::on_goodday_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "We hope you have a plesent day today."
	Mary_say("We hope you have a plesent day today.");
}

void OpendayGui::on_september_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "I look forward to seeing you in september."
	Mary_say("I look forward to seeing you in september.");
}

void OpendayGui::on_zebadiah_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "I have a pet hamster named zebadiah."
	Mary_say("I have a pet hamster named zebadiah.");
}

void OpendayGui::on_lightbulb_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "How many humans does it take to screw in a light bulb?"
	Mary_say("How many humans does it take to screw in a light bulb?");
}

void OpendayGui::on_colour_speak_button_clicked()
{
    // @TODO: ROS Talk to say - "My favourite colour is orange."
	Mary_say("My favourite color is orange.");
}

void OpendayGui::on_Tour_Lab_A_clicked()
{
	Mary_say("Please follow me, I will show you where comp lab AA is.");
    // @TODO: ROS Nav to go - "Comp Lab A"
	//check if there, say something depending on outcome
}

void OpendayGui::on_Tour_Lab_B_clicked()
{
	Mary_say("Please follow me, I will show you where comp lab B is.");
    // @TODO: ROS Nav to go - "Comp Lab B"
	//check if there, say something depending on outcome
}

void OpendayGui::on_Tour_Lab_C_clicked()
{
	Mary_say("Please follow me, I will show you where comp lab C is.");
    // @TODO: ROS Nav to go - "Comp Lab C"
	//check if there, say something depending on outcome
}

void OpendayGui::on_Tour_Lift_clicked()
{
	Mary_say("Please follow me, I will show you where the lift is.");
    // @TODO: ROS Nav to go - "Lift"
	//check if there, say something depending on outcome
}

void OpendayGui::on_Tour_Office_clicked()
{
	Mary_say("Please follow me, I will show you where the offices are.");
    // @TODO: ROS Nav to go - "Offices"
	//check if there, say something depending on outcome
}

void OpendayGui::on_Course_info_clicked()
{
   ui.BasePanel->setCurrentIndex(pCourse);
	Mary_say("These are the course we currently offer in the school of computing.");
}

void OpendayGui::on_Tutors_info_clicked()
{
    ui.BasePanel->setCurrentIndex(pTutors);
	Mary_say("If you study here, these are the people who will be teaching you. Most of them don't bite.");
}

void OpendayGui::on_Close_step1_clicked()
{
    ui.close_step2->setEnabled(true);
}

void OpendayGui::on_David_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>David Cobham</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("David Cobham is the Head of the School of Computer Science.");
}

void OpendayGui::on_Marc_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Marc Hanheide</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("Marc Hanheide is a Senior Lecturer here in the School of computer Science.");
}

void OpendayGui::on_Grzegorz_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Grzegorz Cielniak</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("Grzegorz Cielniak is a Senior Lecturer here in the School of computer Science.");
}

void OpendayGui::on_John_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>John Lewak</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("John Lewak is a Senior Lecturer here in the School of computer Science.");
}

void OpendayGui::on_Kevin_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Kevin Jacques</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("Kevin Jacques is a Principal Teaching Fellow here in the School of computer Science. If you seem him, please ask him about his cat named Marmalade.");
}

void OpendayGui::on_Mark_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Mark Doughty</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("Mark Doughty is a Principal Lecturer here in the School of computer Science.");
}

void OpendayGui::on_Murray_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>John Murray</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("John Murray is a Senior Lecturer here in the School of computer Science.");
}

void OpendayGui::on_Shigang_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Shigang Yue</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("Shigang Yue is a Professor here in the School of computer Science.");
}

void OpendayGui::on_Bashir_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Bashir Al-Diri</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("Bashir Al-Diri is a Senior Lecturer here in the School of computer Science.");
}

void OpendayGui::on_Derek_Face_clicked()
{
    ui.Tutor_info_label->setText("<html><head></head><body><h3>Derek Foster</h3><p>David teraches the following modules:</p><ul><li> <p>Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p><li><p> Computing ABC</p></ul></body></html>");
	Mary_say("Derek Foster is a Lecturer here in the School of computer Science.");
}

void OpendayGui::on_Campus_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pCampus);
	Mary_say("I think this campus is beautiful. I love having everything on my doorstep, without it feeling too busy.");
}

void OpendayGui::on_Ranking_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pRankings);
	Mary_say("This place just keeps getting better, if you don't believe me, take a look at the universities rankings.");

}

void OpendayGui::on_City_button_clicked()
{
    ui.BasePanel->setCurrentIndex(pCity);
	Mary_say("The city of Lincoln is a beautiful place to be.");

}

void OpendayGui::on_VC_message_button_clicked()
{
    ui.BasePanel->setCurrentIndex(pMessage);
	Mary_say("Our Vice Chancellor, Mary Stuart, would like to welcome you to the University.");
}

void OpendayGui::on_Lab_Button_clicked()
{
    ui.BasePanel->setCurrentIndex(pLabs);
Mary_say("We have lots of top end computers which only Computing Students can use. This means you'll never have trouble finding a computer to work on.");
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
	Mary_say("Here is another fun fact");
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
	Mary_say("I was born out of the Strands Project. The Strands team are based in many institution, including this one.");
}

void OpendayGui::on_Strands_Back_clicked()
{
    ui.BasePanel->setCurrentIndex(pLinda);
}

void OpendayGui::on_Full_Screen_Logo_clicked()
{
//To Get Full Screen

}


void OpendayGui::Mary_say(std::string text){

	ac.waitForServer(); //will wait for infinite time  ros_mary_tts::maryttsAction
	ros_mary_tts::maryttsGoal goal;
	goal.text = text;
	ac.sendGoal(goal);
}





}
PLUGINLIB_EXPORT_CLASS(rqt_openday_gui::OpendayGui, rqt_gui_cpp::Plugin)
