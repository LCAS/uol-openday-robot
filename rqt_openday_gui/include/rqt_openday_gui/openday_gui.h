#ifndef OpendayGui_H
#define OpendayGui_H

#include <stdio.h>
#include <signal.h>
#include <string>
#include <QWidget>
#include <QTimer>
#include <QStringList>
#include <boost/thread.hpp>
#include <ros/ros.h>
#include <ros/console.h>
#include <rqt_gui_cpp/plugin.h>
#include <pluginlib/class_list_macros.h>
#include <QResource>
#include "ui_openday_gui.h"
#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <ros_mary_tts/maryttsAction.h>

namespace rqt_openday_gui {

class OpendayGui : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
    
public:
    OpendayGui();
	virtual void initPlugin(qt_gui_cpp::PluginContext& context);
    virtual void shutdownPlugin();
    virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;
    virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);
    
private slots:


    void on_Linda_Button_clicked();

    void on_Main_Menu_Button_clicked();

    void on_SoCS_Button_clicked();

    void on_University_Button_clicked();

    void on_Fun_Facts_Button_clicked();

    void on_Meet_The_Team_Button_clicked();

    void on_Tour_Button_clicked();

    void on_Talking_Button_clicked();

    void on_hello_speak_button_clicked();

    void on_welcome_speak_button_clicked();

    void on_goodday_speak_button_clicked();

    void on_september_speak_button_clicked();

    void on_zebadiah_speak_button_clicked();

    void on_lightbulb_speak_button_clicked();

    void on_colour_speak_button_clicked();

    void on_Tour_Lab_A_clicked();

    void on_Tour_Lab_B_clicked();

    void on_Tour_Lab_C_clicked();

    void on_Tour_Lift_clicked();

    void on_Tour_Office_clicked();

    void on_Course_info_clicked();

    void on_Tutors_info_clicked();

    void on_Close_step1_clicked();

    void on_David_Face_clicked();

    void on_Marc_Face_clicked();

    void on_Grzegorz_Face_clicked();

    void on_John_Face_clicked();

    void on_Kevin_Face_clicked();

    void on_Mark_Face_clicked();

    void on_Murray_Face_clicked();

    void on_Shigang_Face_clicked();

    void on_Bashir_Face_clicked();

    void on_Derek_Face_clicked();

    void on_Campus_Button_clicked();

    void on_Ranking_Button_clicked();

    void on_City_button_clicked();

    void on_VC_message_button_clicked();

    void on_Lab_Button_clicked();

    void on_Meet_The_Team_Back_clicked();

    void on_Tour_Back_clicked();

    void on_Talk_Back_clicked();

    void on_course_Back_clicked();

    void on_Tutor_Back_clicked();

    void on_Lab_Back_clicked();

    void on_campus_Back_clicked();

    void on_Rank_Back_clicked();

    void on_City_Back_clicked();

    void on_VC_Back_clicked();

    void on_Next_Fun_Fact_clicked();


    void on_Strands_Button_clicked();

    void on_Strands_Back_clicked();

	void on_Full_Screen_Logo_clicked();

private:
    Ui::OpendayGui ui;
	QWidget *widget;
	actionlib::SimpleActionClient<ros_mary_tts::maryttsAction> ac;
	void Mary_say(std::string text);
protected:
    static const int pMainMenu = 0;

        static const int pLinda = 1;
            static const int pMeetTheTeam = 2;
            static const int pTour = 3;
            static const int pTalking = 4;
            static const int pStrands = 5;

        static const int pSoCS = 6;
            static const int pCourse = 7;
            static const int pTutors = 8;
            static const int pLabs = 9;

        static const int pUniversity = 10;
            static const int pCampus = 11;
            static const int pRankings = 12;
            static const int pCity = 13;
            static const int pMessage = 14;

        static const int pFunFacts = 15;


    };
}

#endif // OpendayGui_H
