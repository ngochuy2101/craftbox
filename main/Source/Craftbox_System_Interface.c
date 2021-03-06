#ifndef Craftbox_System_Interface

#define Craftbox_System_Interface

/*
--------------------------------------------------
Craftbox_System_Interface.c

High-level layer for communicating with the user through GUI.

Written by Nguyen Ngoc Huy
https://github.com/ngochuy2101
http://craftboxdev.blogspot.com/

TODO:
<+++



>+++

NOTES:
<+++



>+++
--------------------------------------------------
*/

void GQuitCraftbox() {
	
	if(event_type == EVENT_RELEASE) return;
	
	ExitEvent();
	
}

void GUnQuitCraftbox() {
	
	if(event_type == EVENT_RELEASE) return;
	
	reset(QuitDialog,SHOW);
	GMainMenuShow(); 
	
}

void GOpenPropertiesWindow() {
	
	if(event_type == EVENT_RELEASE || !select) return;
	
	reset(RightClickMenu,SHOW);
	
	if( select.ObjectType == Sound) GSoundWindowShow ();
	if( select.ObjectType == Light) GLightWindowShow ();
	if ( select.ObjectType == Particle ) GParticleWindowShow ();
	if( select.ObjectType == ObjectSystem ) {
		
		switch ( select.ObjectSystemType ) {
	
		case Trigger_SpawnNotification: GSpawnNotificationShow(); break;
		case Trigger_SpawnConversation: GSpawnDialogueShow(); break;
		
	}
		
	}
	
	switch(select.ObjectType) {
		
		case Sound: GSoundWindowShow(); break;
		case Light: GLightWindowShow(); break;
		case Particle: GParticleWindowShow(); break;
		default: GPropertiesWindowShow(); break;
		
	}
	
}


void GSpawnNotificationHide () {
	
	wait(1);
	
}

void GSpawnNotificationShow () {
	
	wait(1);

}

void GSpawnDialogueHide () {
	
	reset ( panDialogue , SHOW );

}

void GSpawnDialogueShow () {
	
	set( panDialogue, SHOW );


}

void PassToSelect1String () {
	
	if( event_type == EVENT_RELEASE ) return;
	
	select.String1 = str_create( "#400" );
	
	char *open = file_dialog_open ( " ", "*.*" );
	if( !open ) return;
	else str_cpy( select.String1, _str( open ) );
	
}

PANEL *panDialogue = {
	
	bmap = "panDialogue.png";
	pos_x = 30;
	pos_y = 30;
	
	button( 30, 30, "panDialogue_Selector.png", "panDialogue_Selector.png", "panDialogue_Selector.png", NULL, PassToSelect1String, NULL );
	
	flags = TRANSLUCENT;
	alpha = 50;
	
	on_click = GPanelDrag;
	
	
}

PANEL *RightClickMenu = {
	
	layer = 10;
	
	bmap = "RightclickMenu_backer.bmp";
	button(0,0,"RightclickMenu_button1_on.png","RightclickMenu_button1.png","RightclickMenu_button1_on.png",NULL,GOpenPropertiesWindow,NULL);
	button(0,30,"RightclickMenu_button2_on.png","RightclickMenu_button2.png","RightclickMenu_button2_on.png",NULL,NULL,NULL);
	
}

PANEL *QuitDialog = {
	
	layer = 10;
	
	bmap = "exitConfdialog.png";
	
	button(28,85,"button_exit_win.png","button_exit_win.png","button_exit_win.png",NULL,GQuitCraftbox,NULL);
	button(110,85,"button_exit_win_no.png","button_exit_win_no.png","button_exit_win_no.png",NULL,GUnQuitCraftbox,NULL);
	
	flags = OVERLAY;
	
}

PANEL *seedPanelCover = {
   
   /*
	
	//	bmap = "c07_d.png";
	layer = 10;
	
	button(15,15,"button_startseed.png","button_startseed.png","button_startseed.png",NULL,PerformSeed,NULL);
	button(15,50,"button_editseedmap.png","button_editseedmap.png","button_editseedmap.png",NULL,RecreateSeedMap,NULL);
	button(15,85,"button_selectseedent.png","button_selectseedent.png","button_selectseedent.png",NULL,SeedEntSelector,NULL);
	button(15,120,"button_deleteseedents.png","button_deleteseedents.png","button_deleteseedents.png",NULL,RemoveSeedEnts,NULL);
	
	pos_x = 0;
	pos_y = 0;
	
	flags = OVERLAY;
	
	*/

}

PANEL* canvas_pan = // contains the bitmap that will be written on
{
	
	layer = 15;
	pos_x = 0;
	pos_y = 0;
	
}

PANEL *BackMenu_Items = {
	
	layer = 21;
	bmap = "BackMenu_Item_Background.bmp";
	
	button(0,0,"BackMenu_Item1_on.png","BackMenu_Item1.png","BackMenu_Item1_on.png",NULL,GBackMenuHide,NULL);
	button(0,40,"BackMenu_Item2_on.png","BackMenu_Item2.png","BackMenu_Item2_on.png",NULL,NULL,NULL);
	button(0,80,"BackMenu_Item3_on.png","BackMenu_Item3.png","BackMenu_Item3_on.png",NULL,NULL,NULL);
	button(0,120,"BackMenu_Item4_on.png","BackMenu_Item4.png","BackMenu_Item4_on.png",NULL,NULL,NULL);
	button(0,160,"BackMenu_Item5_on.png","BackMenu_Item5.png","BackMenu_Item5_on.png",NULL,NULL,NULL);
	button(0,200,"BackMenu_Item6_on.png","BackMenu_Item6.png","BackMenu_Item6_on.png",NULL,GQuitToMainMenu,NULL);
	
	pos_x = 50;
	pos_y = 50;
	
	flags = OVERLAY;
	
}


PANEL *BackMenu_Background = {
	
	layer = 20;
	
	bmap = "BackMenu_Background.png";
	
	flags = OVERLAY | TRANSLUCENT;
	
	alpha = 50;
	
}

PANEL *TerrainToolbar = {
	
	layer = 10;
	
	bmap = "TerrainToolbar.png";
	
	//	button(10,10,"terrain_brush_raise.png","terrain_brush_raise.png","terrain_brush_raise.png",NULL,TDeform_changeBrushRaise,NULL);
	//	button(74,10,"terrain_brush_lower.png","terrain_brush_lower.png","terrain_brush_lower.png",NULL,TDeform_changeBrushLower,NULL);
	
	button_toggle(10,10,"terrain_brush_raise_on.png","terrain_brush_raise.png","terrain_brush_raise_on.png","terrain_brush_raise_on.png",NULL,TDeform_changeBrushRaise,NULL);
	button_toggle(74,10,"terrain_brush_raise_on.png","terrain_brush_raise.png","terrain_brush_raise_on.png","terrain_brush_raise_on.png",NULL,TDeform_changeBrushLower,NULL);
	
	button(138,10,"load_upload.png""load_upload.png","load_upload.png",NULL,GTerrainSaveGeoWrapper,NULL);
	button(202,10,"load_download.png","load_download.png","load_download.png",NULL,GTerrainLoadGeoWrapper,NULL);
	
	button(403,84,"TerrainToolbar_Close_on.png","TerrainToolbar_Close.png","TerrainToolbar_Close_on.png",NULL,GToggleTerrainEditor,NULL);
	
	
	hslider(289,34,155,"slider.bmp",500,5000,bSize);
	hslider(289,72,155,"slider.bmp",5,25,brush_speed);
	
	on_click = GPanelDrag;
	
}

PANEL *pLoadBar = {
	
	layer = 999;
	pos_x = 0;
	pos_y = 0;
	
	// Purple mountain majesty sRGBB  (r, g, b)	(150, 120, 182)
	red = 150;
	green = 120;
	blue = 182;
	
}

PANEL *InDev = {
	
	layer = 999;
	
	bmap = "InDev.png";
	button(170,184,"InDev_Close.png","InDev_Close.png","InDev_Close.png",NULL,GInDevHide,NULL);
	
}

PANEL *Playtest_Loadscreen = {
	
	layer = 100;
	
	
}

PANEL *Blackboard = {
	
	layer = 25;
	
	bmap = "notificationGround.bmp";
	button(0,0,"notification.bmp","notification.bmp","notification.bmp",NULL,GBlackboardAlphaRestore,GBlackboardAlphaFade);
	
	flags = TRANSLUCENT;
	
}

PANEL *Stats = {
	
	layer = 1;
	
	bmap = "Stats.png";
	flags = OVERLAY | TRANSLUCENT;
	alpha = 50;
	
	button(261,251,"button_stats_off.png","button_stats_off.png","button_stats_off.png",NULL,GToggleStatistics,NULL);
	
	on_click = GPanelDrag;
	
}

PANEL *MusicPlayer = {
	
	layer = 15;
	
	bmap = "MusicPlayerInterface.png";
	
	button(0,0,"mp_media_previous.png","mp_media_previous.png","mp_media_previous.png",NULL,mpPrev,NULL);
	button(138,0,"mp_media_pause.png","mp_media_pause.png","mp_media_pause.png",NULL,mpPause,NULL);
	button(276,0,"mp_media_play.png","mp_media_play.png","mp_media_play.png",NULL,mpResume,NULL);
	button(414,0,"mp_media_next.png","mp_media_next.png","mp_media_next.png",NULL,mpNext,NULL);
	button_toggle(336,156,"Musicplayer_random_on.png","Musicplayer_random_off.png","Musicplayer_random_on.png","Musicplayer_random_on.png",NULL,GToggleMusicPlayerRandomize,NULL);
	
	flags = OVERLAY;
	
	on_click = GPanelDrag;
	
}

TEXT *MusicPlayerInfo = {
	
	layer = 20;
	
	strings(2);
	string(_mpSongTemp,_mpCount);
	
	font = "Arial#20b";
	
	//	flags = SHOW;
	
}

PANEL *FPCrosshair = {
	
	layer = 15;
	bmap = "crosshair.png";
	
	flags = OVERLAY;
	
}

PANEL *CreateWorld = {
	
	layer = 998;
	bmap = "white.bmp";
	
	flags = TRANSLUCENT;
	alpha = 100;
	
}

PANEL *CreateWorldCoffee = {
	
	layer = 999;
	bmap = "coffee_badge.png";
	
}

PANEL *NewGame_PreviewButton = {
	
	bmap = "button_PreviewScene_off.png";
	button(0,0,"button_PreviewScene_on.png","button_PreviewScene_off.png","button_PreviewScene_on.png",NULL,GNewGame_UnPreviewScene,GNewGame_PreviewScene);
	
	//	flags = SHOW;
	
}


PANEL *NewGame_ScreenLeft = {
	
	layer = 2;
	
	button(0,0,"arrow_left.png","arrow_left.png","arrow_left.png",NULL,GSwitchNewGameScreen,NULL);
	button(0,0,"black.bmp","black.bmp","black.bmp",NULL,NULL,NULL);
	
	flags = OVERLAY;
	
}

PANEL *NewGame_ScreenRight = {
	
	layer = 2;
	
	button(0,0,"black.bmp","black.bmp","black.bmp",NULL,NULL,NULL);
	button(0,0,"arrow_right.png","arrow_right.png","arrow_right.png",NULL,GSwitchNewGameScreen,NULL);
	
	flags = OVERLAY;
	
}

PANEL *NewGame_Screen1 = {
	
	bmap = "NewGame_Screen1.bmp";
	flags =  TRANSLUCENT;
	alpha = 75;
	
	button(121,345,"button_NewGame_Screen_on.bmp","button_NewGame_Screen.bmp","button_NewGame_Screen_on.bmp",NULL,GNewGame_ChooseWorld,NULL);
	button(517,345,"button_NewGame_Screen_on.bmp","button_NewGame_Screen.bmp","button_NewGame_Screen_on.bmp",NULL,GNewGame_ChooseWorld,NULL);
	
}

PANEL *NewGame_ScreenDyn_Step1 = {
	
	bmap = "NewGame_ScreenDyn_Step1.bmp";
	
	button_toggle(30,96,"NewGame_Checkbox_Lensflare_On.bmp","NewGame_Checkbox_Lensflare_Off.bmp","NewGame_Checkbox_Lensflare_On.bmp","NewGame_Checkbox_Lensflare_On.bmp",NULL,NULL,NULL);
	button_toggle(30,126,"NewGame_Checkbox_Sun_On.bmp","NewGame_Checkbox_Sun_Off.bmp","NewGame_Checkbox_Sun_On.bmp","NewGame_Checkbox_Sun_On.bmp",NULL,NULL,NULL);
	button_toggle(30,156,"NewGame_Checkbox_Moon_On.bmp","NewGame_Checkbox_Moon_Off.bmp","NewGame_Checkbox_Moon_On.bmp","NewGame_Checkbox_Moon_On.bmp",NULL,NULL,NULL);
	button_toggle(30,186,"NewGame_Checkbox_Stars_On.bmp","NewGame_Checkbox_Stars_Off.bmp","NewGame_Checkbox_Stars_On.bmp","NewGame_Checkbox_Stars_On.bmp",NULL,NULL,NULL);
	
	button_radio(36,250."NewGame_Radiobox_Rain_On.bmp","NewGame_Radiobox_Rain_Off.bmp","NewGame_Radiobox_Rain_On.bmp",NULL,GWeatherMode_RainOnly,NULL);
	button_radio(36,280,"NewGame_Radiobox_Snow_On.bmp","NewGame_Radiobox_Snow_Off.bmp","NewGame_Radiobox_Snow_On.bmp",NULL,GWeatherMode_SnowOnly,NULL);
	button_radio(36,310,"NewGame_Radiobox_Both_On.bmp","NewGame_Radiobox_Both_Off.bmp","NewGame_Radiobox_Both_On.bmp",NULL,GWeatherMode_RainSnow,NULL);
	button_radio(36,340,"NewGame_Radiobox_Nothing_On.bmp","NewGame_Radiobox_Nothing_Off.bmp","NewGame_Radiobox_Nothing_On.bmp",NULL,GWeatherMode_Nothing,NULL);
	
	hslider(503,115,274,"SliderKnob.bmp",5,20,_DayDuration); // [0..150]
	hslider(503,164,274,"SliderKnob.bmp",5,20,_NightDuration); // [0..150]
	hslider(503,215,274,"SliderKnob.bmp",5,40,_MoonScaleFactor); // [2,5..40]
	hslider(503,263,274,"SliderKnob.bmp",1,5,_NightScaleFactor); // [0,5..5]
	hslider(503,318,274,"SliderKnob.bmp",25,200,_NightSkySpeed); // [0..200]
	
	flags =  TRANSLUCENT;
	
	alpha = 75;
	
}

PANEL *NewGame_ScreenStatic_Step1 = {
	
	bmap = "NewGame_ScreenStatic_Step1.bmp";
	
	hslider(323,107,271,"SliderKnob.bmp",-200,300,_sun_light); // actually I found sun_light ranged from -200 to 200+
	button_toggle(37,166,"NewGame_Checkbox_Fog_On.bmp","NewGame_Checkbox_Fog_Off.bmp","NewGame_Checkbox_Fog_On.bmp","NewGame_Checkbox_Fog_On.bmp",NULL,NULL,NULL);
	
	hslider(283,255,271,"SliderKnob.bmp",0,255,_d3d_fogcolor1_red);
	hslider(283,291,271,"SliderKnob.bmp",0,255,_d3d_fogcolor1_blue);
	hslider(283,329,271,"SliderKnob.bmp",0,255,_d3d_fogcolor1_green);
	hslider(283,370,271,"SliderKnob.bmp",100,50000,_camera_fog_end);
	
	flags = TRANSLUCENT;
	alpha = 75;
	
}

PANEL *NewGame_Screen3 = {
	
	bmap = "NewGame_Screen3.bmp";
	
	button(661,354,"button_Start_on.png","button_Start_off.png","button_Start_on.png",NULL,LaunchGameSession,NULL);
	
	button_toggle(40,264,"checkbox_WaterPlane_on.png","checkbox_WaterPlane_off.png","checkbox_WaterPlane_on.png","checkbox_WaterPlane_on.png",NULL,NULL,NULL);
	
	flags = TRANSLUCENT;
	alpha = 75;
	
}

PANEL *MainMenu_Bar = {
	
	layer = 1;
	
	bmap = "bar.tga";
	
	pos_x = 0;
	pos_y = 0;
	
	flags = TRANSLUCENT;
	
	alpha = 75;
	
}

PANEL *LoadGame = {
	
	layer = 1;
	
	bmap = "LoadGame.bmp";
	
	flags = TRANSLUCENT;
	alpha = 75;
	
}

PANEL *Options_Graphics = {
	
	layer = 4;
	
	bmap = "Options_Graphics.bmp";
	
	//
	button(241,81,"arrow_left.png","arrow_left.png","arrow_left.png",NULL,GOptionsAdjustSettings,NULL);
	button(400,81,"arrow_right.png","arrow_right.png","arrow_right.png",NULL,GOptionsAdjustSettings,NULL);
	
	button(241,111,"arrow_left.png","arrow_left.png","arrow_left.png",NULL,GOptionsAdjustSettings,NULL);
	button(400,111,"arrow_right.png","arrow_right.png","arrow_right.png",NULL,GOptionsAdjustSettings,NULL);
	
	button(241,141,"arrow_left.png","arrow_left.png","arrow_left.png",NULL,GOptionsAdjustSettings,NULL);
	button(400,141,"arrow_right.png","arrow_right.png","arrow_right.png",NULL,GOptionsAdjustSettings,NULL);
	
	button(241,171,"arrow_left.png","arrow_left.png","arrow_left.png",NULL,GOptionsAdjustSettings,NULL);
	button(400,171,"arrow_right.png","arrow_right.png","arrow_right.png",NULL,GOptionsAdjustSettings,NULL);
	
	button(241,201,"arrow_left.png","arrow_left.png","arrow_left.png",NULL,GOptionsAdjustSettings,NULL);
	button(400,201,"arrow_right.png","arrow_right.png","arrow_right.png",NULL,GOptionsAdjustSettings,NULL);
	
	button_toggle(30,269,"Options_checkbox_SSAO_on.bmp","Options_checkbox_SSAO_off.bmp","Options_checkbox_SSAO_on.bmp","Options_checkbox_SSAO_on.bmp",NULL,NULL,NULL);
	button_toggle(30,300,"Options_checkbox_HDR_on.bmp","Options_checkbox_HDR_off.bmp","Options_checkbox_HDR_on.bmp","Options_checkbox_HDR_on.bmp",NULL,NULL,NULL);
	button_toggle(250,269,"Options_checkbox_DoF_on.bmp","Options_checkbox_DoF_off.bmp","Options_checkbox_DoF_on.bmp","Options_checkbox_DoF_on.bmp",NULL,NULL,NULL);
	button_toggle(250,300,"Options_checkbox_Shadows_on.bmp","Options_checkbox_Shadows_off.bmp","Options_checkbox_Shadows_on.bmp","Options_checkbox_Shadows_on.bmp",NULL,NULL,NULL);
	
	button_toggle(480,269,"Options_checkbox_OS_on.bmp","Options_checkbox_OS_off.bmp","Options_checkbox_OS_on.bmp","Options_checkbox_OS_on.bmp",NULL,NULL,NULL);
	button_toggle(480,300,"Options_checkbox_PP_on.bmp","Options_checkbox_PP_off.bmp","Options_checkbox_PP_on.bmp","Options_checkbox_PP_on.bmp",NULL,NULL,NULL);
	
	
	//	button(241,231,"arrow_left.png","arrow_left.png","arrow_left.png",GOptionsAdjustSettings,NULL,NULL);
	//	button(400,231,"arrow_right.png","arrow_right.png","arrow_right.png",GOptionsAdjustSettings,NULL,NULL);
	//	
	
	//
	button(216,8,"button_Options_Graphics_on.png","button_Options_Graphics.png","button_Options_Graphics_on.png",NULL,GOptions_Graphics,NULL);
	button(316,8,"button_Options_Sound_on.png","button_Options_Sound.png","button_Options_Sound_on.png",NULL,GOptions_Sound,NULL);
	button(450,8,"button_Options_Themes_on.png","button_Options_Themes.png","button_Options_Themes_on.png",NULL,GOptions_Themes,NULL);
	button(555,8,"button_Options_Maintenance_on.png","button_Options_Maintenance.png","button_Options_Maintenance_on.png",NULL,GOptions_Maintenance,NULL);
	
	button(24,349,"button_Options_Back_on.png","button_Options_Back.png","button_Options_Back_on.png",NULL,GOptions_SaveSettings,NULL);
	
	flags = TRANSLUCENT;
	
	alpha = 80;
	
	//	on_click = GPanelDrag;
	
}

PANEL *Options_Sound = {
	
	layer = 4;
	
	bmap = "Options_Sound.bmp";
	
	//
	button(241,81,"arrow_left.png","arrow_left.png","arrow_left.png",NULL,GOptionsAdjustSettings,NULL);
	button(400,81,"arrow_right.png","arrow_right.png","arrow_right.png",NULL,GOptionsAdjustSettings,NULL);
	
	button(241,111,"arrow_left.png","arrow_left.png","arrow_left.png",NULL,GOptionsAdjustSettings,NULL);
	button(400,111,"arrow_right.png","arrow_right.png","arrow_right.png",NULL,GOptionsAdjustSettings,NULL);
	
	button(241,141,"arrow_left.png","arrow_left.png","arrow_left.png",NULL,GOptionsAdjustSettings,NULL);
	button(400,141,"arrow_right.png","arrow_right.png","arrow_right.png",NULL,GOptionsAdjustSettings,NULL);
	
	//
	button(216,8,"button_Options_Graphics_on.png","button_Options_Graphics.png","button_Options_Graphics_on.png",NULL,GOptions_Graphics,NULL);
	button(316,8,"button_Options_Sound_on.png","button_Options_Sound.png","button_Options_Sound_on.png",NULL,GOptions_Sound,NULL);
	button(450,8,"button_Options_Themes_on.png","button_Options_Themes.png","button_Options_Themes_on.png",NULL,GOptions_Themes,NULL);
	button(555,8,"button_Options_Maintenance_on.png","button_Options_Maintenance.png","button_Options_Maintenance_on.png",NULL,GOptions_Maintenance,NULL);
	
	button(24,349,"button_Options_Back_on.png","button_Options_Back.png","button_Options_Back_on.png",NULL,GOptions_SaveSettings,NULL);
	
	flags = TRANSLUCENT;
	
	alpha = 80;
	
}

PANEL *Options_Themes = {
	
	layer = 4;
	
	bmap = "Options_Themes.bmp";
	
	button(216,8,"button_Options_Graphics_on.png","button_Options_Graphics.png","button_Options_Graphics_on.png",NULL,GOptions_Graphics,NULL);
	button(316,8,"button_Options_Sound_on.png","button_Options_Sound.png","button_Options_Sound_on.png",NULL,GOptions_Sound,NULL);
	button(450,8,"button_Options_Themes_on.png","button_Options_Themes.png","button_Options_Themes_on.png",NULL,GOptions_Themes,NULL);
	button(555,8,"button_Options_Maintenance_on.png","button_Options_Maintenance.png","button_Options_Maintenance_on.png",NULL,GOptions_Maintenance,NULL);
	
	button(24,349,"button_Options_Back_on.png","button_Options_Back.png","button_Options_Back_on.png",NULL,GOptions_SaveSettings,NULL);
	
	flags = TRANSLUCENT;
	
	alpha = 80;
	
}

PANEL *Options_Maintenance = {
	
	layer = 4;
	
	bmap = "Options_Maintenance.bmp";
	
	button(216,8,"button_Options_Graphics_on.png","button_Options_Graphics.png","button_Options_Graphics_on.png",NULL,GOptions_Graphics,NULL);
	button(316,8,"button_Options_Sound_on.png","button_Options_Sound.png","button_Options_Sound_on.png",NULL,GOptions_Sound,NULL);
	button(450,8,"button_Options_Themes_on.png","button_Options_Themes.png","button_Options_Themes_on.png",NULL,GOptions_Themes,NULL);
	button(555,8,"button_Options_Maintenance_on.png","button_Options_Maintenance.png","button_Options_Maintenance_on.png",NULL,GOptions_Maintenance,NULL);
	
	button(24,349,"button_Options_Back_on.png","button_Options_Back.png","button_Options_Back_on.png",NULL,GOptions_SaveSettings,NULL);
	
	button(27,100,"button_benchmark_on.png","button_benchmark_off.png","button_benchmark_on.png",NULL,NULL,NULL);
	button(27,140,"button_redetectPC_on.png","button_redetectPC_off.png","button_redetectPC_on.png",NULL,NULL,NULL);
	button(24,180,"button_openConsole_on.png","button_openConsole_off.png","button_openConsole_on.png",NULL,OpenConsole,NULL);
	
	flags = TRANSLUCENT;
	
	alpha = 80;
	
}

PANEL *InputBox_GROUNDSTR = {
	
	/*
	
	EVENT_RELEASE and EVENT_BUTTONUP can be used to distinguish whether functionOff was triggered by leaving the button area 
	or releasing the mouse button. EVENT_CLICK and EVENT_CLICKUP can be used to distinguish whether the mouse click switches the toggle button on or off. 
	
	*/
	
	layer = 10;
	
	bmap = "InputPalette_4.bmp";
	
	button_radio(0,0,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToGROUNDSTR,NULL);
	button_radio(0,27,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToGROUNDSTR,NULL);
	button_radio(0,54,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToGROUNDSTR,NULL);
	button_radio(0,81,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToGROUNDSTR,NULL);
	
	button(247,0,"sort_up.png","sort_up.png","sort_up.png",NULL,GGROUNDSTR_Up,NULL);
	button(247,76,"sort_down.png","sort_down.png","sort_down.png",NULL,GGROUNDSTR_Down,NULL);
	
	flags = OVERLAY | TRANSLUCENT;

	alpha = 50;
	
}

PANEL *InputBox_SKYSTR = {
	
	layer = 10;
	
	bmap = "InputPalette_4.bmp";
	
	button_radio(0,0,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToSKYSTR,NULL);
	button_radio(0,27,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToSKYSTR,NULL);
	button_radio(0,54,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToSKYSTR,NULL);
	button_radio(0,81,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToSKYSTR,NULL);
	
	button(247,0,"sort_up.png","sort_up.png","sort_up.png",NULL,GSKYSTR_Up,NULL);
	button(247,76,"sort_down.png","sort_down.png","sort_down.png",NULL,GSKYSTR_Down,NULL);
	
	flags = OVERLAY | TRANSLUCENT;

	alpha = 50;
	
}

PANEL *InputBox_LOADGAMESTR = {
	
	layer = 10;
	
	bmap = "InputPalette_8.bmp";
	
	button_radio(0,0,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToLOADGAMESTR,NULL);
	button_radio(0,27,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToLOADGAMESTR,NULL);
	button_radio(0,54,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToLOADGAMESTR,NULL);
	button_radio(0,81,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToLOADGAMESTR,NULL);
	button_radio(0,108,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToLOADGAMESTR,NULL);
	button_radio(0,135,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToLOADGAMESTR,NULL);
	button_radio(0,162,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToLOADGAMESTR,NULL);
	button_radio(0,189,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,PassToLOADGAMESTR,NULL);
	
	button(247,0,"sort_up.png","sort_up.png","sort_up.png",NULL,GLOADGAMESTR_Up,NULL);
	button(247,184,"sort_down.png","sort_down.png","sort_down.png",NULL,GLOADGAMESTR_Down,NULL);
	
	flags = OVERLAY | TRANSLUCENT;

	alpha = 50;
	
}

PANEL *InsertObject_Inputter = {
	
	/*
	
	EVENT_RELEASE and EVENT_BUTTONUP can be used to distinguish whether functionOff was triggered by leaving the button area 
	or releasing the mouse button. EVENT_CLICK and EVENT_CLICKUP can be used to distinguish whether the mouse click switches the toggle button on or off. 
	
	*/
	
	bmap = "InputPalette_20.bmp";
	
	button_radio(0,0,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,30,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,60,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,90,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,120,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	
	button_radio(0,150,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,180,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,210,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,240,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,270,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	
	button_radio(0,300,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,330,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,360,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,390,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,420,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	
	button_radio(0,450,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,480,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,510,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,540,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	button_radio(0,570,"Inputter_Button_on.bmp","InsertObject_Inputter_Button.bmp","Inputter_Button_on.bmp",NULL,GSelectObject,NULL);
	
	button_radio(247,0,"sort_up.png","sort_up.png","sort_up.png",NULL,GTEMPSTR_Up,NULL);
	button_radio(247,565,"sort_down.png","sort_down.png","sort_down.png",NULL,GTEMPSTR_Down,NULL);

	flags = TRANSLUCENT;

	alpha = 25;

}

PANEL *InsertParticle = {
	
	layer = 6;
	
	button(0,0,"Particle1.bmp","Particle1.bmp","Particle1.bmp",NULL,GSelectParticle,NULL);
	button(80,0,"Particle2.bmp","Particle2.bmp","Particle2.bmp",NULL,GSelectParticle,NULL);
	button(160,0,"Particle3.bmp","Particle3.bmp","Particle3.bmp",NULL,GSelectParticle,NULL);
	button(240,0,"Particle4.bmp","Particle4.bmp","Particle4.bmp",NULL,GSelectParticle,NULL);
	
	button(0,40,"Particle5.bmp","Particle5.bmp","Particle5.bmp",NULL,GSelectParticle,NULL);
	button(80,40,"Particle6.bmp","Particle6.bmp","Particle6.bmp",NULL,GSelectParticle,NULL);
	button(160,40,"Particle7.bmp","Particle7.bmp","Particle7.bmp",NULL,GSelectParticle,NULL);
	button(240,40,"Particle8.bmp","Particle8.bmp","Particle8.bmp",NULL,GSelectParticle,NULL);
	
	button(0,80,"Particle9.bmp","Particle9.bmp","Particle9.bmp",NULL,GSelectParticle,NULL);
	button(80,80,"Particle10.bmp","Particle10.bmp","Particle10.bmp",NULL,GSelectParticle,NULL);
	button(160,80,"Particle11.bmp","Particle11.bmp","Particle11.bmp",NULL,GSelectParticle,NULL);
	button(240,80,"Particle12.bmp","Particle12.bmp","Particle12.bmp",NULL,GSelectParticle,NULL);
	
	button(0,80,"Particle13.bmp","Particle13.bmp","Particle13.bmp",NULL,GSelectParticle,NULL);
	button(80,80,"Particle14.bmp","Particle14.bmp","Particle14.bmp",NULL,GSelectParticle,NULL);
	button(160,80,"Particle15.bmp","Particle15.bmp","Particle15.bmp",NULL,GSelectParticle,NULL);
	button(240,80,"Particle16.bmp","Particle16.bmp","Particle16.bmp",NULL,GSelectParticle,NULL);
	
	button(0,80,"Particle17.bmp","Particle17.bmp","Particle17.bmp",NULL,GSelectParticle,NULL);
	button(80,80,"Particle18.bmp","Particle18.bmp","Particle18.bmp",NULL,GSelectParticle,NULL);
	button(160,80,"Particle19.bmp","Particle19.bmp","Particle19.bmp",NULL,GSelectParticle,NULL);
	button(240,80,"Particle20.bmp","Particle20.bmp","Particle20.bmp",NULL,GSelectParticle,NULL);
	
}

PANEL *InsertSystemObjects = {
	
	layer = 6;
	
	button(0,0,"sys_foot_on.jpg","sys_foot.jpg","sys_foot_on.jpg",NULL,SECreate_PlayerNormal,NULL);
	button(138,0,"sys_bike_on.jpg","sys_bike.jpg","sys_bike_on.jpg",NULL,SECreate_PlayerBike,NULL);
	
	//button( 0, 158 ,"sys_spawnwarning.png","sys_spawnwarning.png","sys_spawnwarning.png",NULL,SECreate_SpawnNotification,NULL);
	//button( 138, 158,"sys_openconversation.png","sys_openconversation.png","sys_openconversation.png",NULL,NULL,NULL);
	
	/* 
	
	// 128 + 30
	button(0,158,"sys_adjustfog.JPG","sys_adjustfog.JPG","sys_adjustfog.JPG",NULL,NULL,NULL);
	button(138,158,"sys_changemusic.png","sys_changemusic.png","sys_changemusic.png",NULL,NULL,NULL);
	button(266,158,"sys_video.jpg","sys_video.jpg","sys_video.jpg",NULL,NULL,NULL);
	
	// 158 + 128 + 30
	button(0,308,"sys_openconversation.png","sys_openconversation.png","sys_openconversation.png",NULL,NULL,NULL);
	button(138,308,"sys_openletter.png","sys_openletter.png","sys_openletter.png",NULL,NULL,NULL);
	button(266,308,"sys_spawnwarning.png","sys_spawnwarning.png","sys_spawnwarning.png",NULL,NULL,NULL);
	
	*/
	
}

PANEL *InsertObject = {
	
	layer = 4;
	
	bmap = "InsertObject.png";
	//	
	//	button(0,0,"button_close_on.bmp","button_close_off.bmp","button_close_over.bmp",NULL,GWindowClose,NULL);
	
	button_toggle(40,30,"IO_ObjectTab_On.png","IO_ObjectTab_Off.png","IO_ObjectTab_On.png",,"IO_SoundTab_On.png",NULL,GObjectTypeTab_Switcher,NULL);
	button_toggle(150,30,"IO_SoundTab_On.png","IO_SoundTab_Off.png","IO_SoundTab_On.png","IO_SoundTab_On.png",NULL,GObjectTypeTab_Switcher,NULL);
	button_toggle(260,30,"IO_ParticleTab_On.png","IO_ParticleTab_Off.png","IO_ParticleTab_On.png","IO_ParticleTab_On.png",NULL,GObjectTypeTab_Switcher,NULL);
	button_toggle(370,30,"IO_LightTab_On.png","IO_LightTab_Off.png","IO_LightTab_On.png","IO_LightTab_On.png",NULL,GObjectTypeTab_Switcher,NULL);
	button_toggle(480,30,"IO_SpriteTab_On.png","IO_SpriteTab_Off.png","IO_SpriteTab_On.png","IO_SpriteTab_On.png",NULL,GObjectTypeTab_Switcher,NULL);
	//	button_toggle(590,30,"IO_TerrainTab_On.png","IO_TerrainTab_Off.png","IO_TerrainTab_On.png","IO_TerrainTab_On.png",NULL,GObjectTypeTab_Switcher,NULL);
	//	button_toggle(810,30,"IO_BlockTab_On.png","IO_BlockTab_Off.png","IO_BlockTab_On.png","IO_BlockTab_On.png",NULL,GObjectTypeTab_Switcher,NULL);
	button_toggle(590,30,"IO_SysTab_On.png","IO_SysTab_Off.png","IO_SysTab_On.png","IO_SysTab_On.png",NULL,GObjectTypeTab_Switcher,NULL);
	
	button(860,698,"closeInsertobject.png","closeInsertobject_on.png","closeInsertobject.png",NULL,GInsertObjectHide,NULL);
	
	flags = OVERLAY | TRANSLUCENT;
	
	alpha = 50;
	
	//	on_click = GPanelDrag;
	
}


PANEL *empty = {
	
	layer = 0;
	
}

PANEL *IO_ObjectTab = {
	
	layer = 5;
	
	// 1->8
	button_toggle(0,0,"IO_ObjectTab_anms_on.png","IO_ObjectTab_anms.png","IO_ObjectTab_anms_on.png","IO_ObjectTab_anms_on.png",NULL,GIO_ObjectTab_SwitchTab,NULL);
	button_toggle(0,40,"IO_ObjectTab_archs_on.png","IO_ObjectTab_archs.png","IO_ObjectTab_archs_on.png",,"IO_ObjectTab_archs_on.png",NULL,GIO_ObjectTab_SwitchTab,NULL);
	button_toggle(0,80,"IO_ObjectTab_chars_on.png","IO_ObjectTab_chars.png","IO_ObjectTab_chars_on.png","IO_ObjectTab_chars_on.png",NULL,GIO_ObjectTab_SwitchTab,NULL);
	button_toggle(0,120,"IO_ObjectTab_etc_on.png","IO_ObjectTab_etc.png","IO_ObjectTab_etc_on.png","IO_ObjectTab_etc_on.png",NULL,GIO_ObjectTab_SwitchTab,NULL);
	button_toggle(0,160,"IO_ObjectTab_food_on.png","IO_ObjectTab_food.png","IO_ObjectTab_food_on.png","IO_ObjectTab_food_on.png",NULL,GIO_ObjectTab_SwitchTab,NULL);
	button_toggle(0,200,"IO_ObjectTab_machs_on.png","IO_ObjectTab_machs.png","IO_ObjectTab_machs_on.png","IO_ObjectTab_machs_on.png",NULL,GIO_ObjectTab_SwitchTab,NULL);
	button_toggle(0,240,"IO_ObjectTab_plants_on.png","IO_ObjectTab_plants.png","IO_ObjectTab_plants_on.png","IO_ObjectTab_plants_on.png",NULL,GIO_ObjectTab_SwitchTab,NULL);
	button_toggle(0,280,"IO_ObjectTab_tportts_on.png","IO_ObjectTab_tportts.png","IO_ObjectTab_tportts_on.png","IO_ObjectTab_tportts_on.png",NULL,GIO_ObjectTab_SwitchTab,NULL);
	
}

PANEL *LightPresets = {
	
	layer = 6;
	
	button(0,0,"LightPreset1.png","LightPreset1.png","LightPreset1.png",NULL,GSelectLight,NULL);
	button(128,0,"LightPreset2.png","LightPreset2.png","LightPreset2.png",NULL,GSelectLight,NULL);
	button(256,0,"LightPreset3.png","LightPreset3.png","LightPreset3.png",NULL,GSelectLight,NULL);
	button(384,0,"LightPreset4.png","LightPreset4.png","LightPreset4.png",NULL,GSelectLight,NULL);
	
	button(0,128,"LightPreset5.png","LightPreset5.png","LightPreset5.png",NULL,GSelectLight,NULL);
	button(128,128,"LightPreset6.png","LightPreset6.png","LightPreset6.png",NULL,GSelectLight,NULL);
	button(256,128,"LightPreset7.png","LightPreset7.png","LightPreset7.png",NULL,GSelectLight,NULL);
	button(384,128,"LightPreset8.png","LightPreset8.png","LightPreset8.png",NULL,GSelectLight,NULL);
	
	button(0,256,"LightPreset9.png","LightPreset9.png","LightPreset9.png",NULL,GSelectLight,NULL);
	button(128,256,"LightPreset10.png","LightPreset10.png","LightPreset10.png",NULL,GSelectLight,NULL);
	button(256,256,"LightPreset11.png","LightPreset11.png","LightPreset11.png",NULL,GSelectLight,NULL);
	button(384,256,"LightPreset12.png","LightPreset12.png","LightPreset12.png",NULL,GSelectLight,NULL);
	
}

PANEL *panProp = {
	
	layer = 2;
	
	bmap = panProp1_IMG;
	
	button(265,1,"button_close_on.bmp","button_close_off.bmp","button_close_over.bmp",NULL,GPropertiesWindowHide,NULL);
	
	//	button(0,0,"button_apply_on.bmp","button_apply.bmp","button_apply_on.bmp",NULL,NULL,NULL);
	
	button_toggle(110,85,flag_BIRGHT_on,flag_BIRGHT,flag_BIRGHT_on,flag_BIRGHT_on,NULL,NULL,NULL);
	button_toggle(110,105,flag_INVISIBLE_on,flag_INVISIBLE,flag_INVISIBLE_on,flag_INVISIBLE_on,NULL,NULL,NULL);
	button_toggle(110,125,flag_NOFOG_on,flag_NOFOG,flag_NOFOG_on,flag_NOFOG_on,NULL,NULL,NULL);
	button_toggle(110,145,flag_OVERLAY_on,flag_OVERLAY,flag_OVERLAY_on,flag_OVERLAY_on,NULL,NULL,NULL);
	button_toggle(110,165,flag_PASSABLE_on,flag_PASSABLE,flag_PASSABLE_on,flag_PASSABLE_on,NULL,NULL,NULL);
	button_toggle(110,185,flag_POLYGON_on,flag_POLYGON,flag_POLYGON_on,flag_POLYGON_on,NULL,NULL,NULL);
	button_toggle(110,205,flag_SHADOW_on,flag_SHADOW,flag_SHADOW_on,flag_SHADOW_on,NULL,NULL,NULL);
	button_toggle(110,225,flag_TRANSLUCENT_on,flag_TRANSLUCENT,flag_TRANSLUCENT_on,flag_TRANSLUCENT_on,NULL,NULL,NULL);
	
	button(110,255,"button_default_on.bmp","button_default_off.bmp","button_default_on.bmp",NULL,ObjectRestoreDefault,NULL);
	button(220,255,"button_randomrotate_on.bmp","button_randomrotate_off.bmp","button_randomrotate_on.bmp",NULL,ObjectRandomPan,NULL);
	
	hslider(110,301,100,slider,0,100,v_alpha);	
	hslider(110,345,100,slider,0,100,v_ambient);
	
	
	on_click = GPanelDrag;
	
	flags = TRANSLUCENT | OVERLAY;
	
	alpha = 50;
}

/*

PANEL *panMat_Sub1 = {
	layer = 2;
	
	bmap = "panMatEd.bmp";
	
	button(0,0,"button_close_on.bmp","button_close_off.bmp","button_close_over.bmp",NULL,GWindowClose,NULL);
	button(4,20,"button_savemat_on.bmp","button_savemat_off.bmp","button_savemat_on.bmp",NULL,MaterialSave,NULL);
	
	// we need 14 sliders for ambient x3, specular x3, diffuse x3 and emissive x3
	// +power, +alpha.
	
	hslider(134,41,100,"slider.bmp",0,255,v_emissive_r);
	hslider(134,57,100,"slider.bmp",0,255,v_emissive_g);
	hslider(134,75,100,"slider.bmp",0,255,v_emissive_b);
	hslider(134,108,100,"slider.bmp",0,255,v_ambient_r);
	hslider(134,126,100,"slider.bmp",0,255,v_ambient_g);
	hslider(134,143,100,"slider.bmp",0,255,v_ambient_b);
	
	hslider(134,181,100,"slider.bmp",0,255,v_diffuse_r);
	hslider(134,199,100,"slider.bmp",0,255,v_diffuse_g);
	hslider(134,216,100,"slider.bmp",0,255,v_diffuse_b);
	
	hslider(134,251,100,"slider.bmp",0,255,v_specular_r);
	hslider(134,269,100,"slider.bmp",0,255,v_specular_g);
	hslider(134,286,100,"slider.bmp",0,255,v_specular_b);
	
	hslider(327,303,100,"slider.bmp",0,10,v_power);
	//	hslider(0,0,100,"slider.bmp",0,255,v_alpha_m);
	
	on_click = GPanelDrag;
	
	flags = OVERLAY | TRANSLUCENT;
}

*/

PANEL *panSnd = {
	
	layer = 3;
	
	button(220,1,"button_close_on.bmp","button_close_off.bmp","button_close_over.bmp",NULL,GSoundWindowHide,NULL);
	
	bmap = "panSnd.bmp";
	
	on_click = GPanelDrag;
	
	flags = TRANSLUCENT;
	
}

PANEL *panParticle = {
	
	layer = 3;
	
	button(265,1,"button_close_on.bmp","button_close_off.bmp","button_close_over.bmp",NULL,GParticleWindowHide,NULL);
	
	bmap = "panParticle.bmp";
	
	on_click = GPanelDrag;
	
	flags = TRANSLUCENT;
	
}


PANEL *panMain_Top = {
	layer = 0;
	
	bmap = "panMain_Top.bmp";
	
	button_toggle(0,0,flag_MOVE_on,flag_MOVE,flag_MOVE_on,flag_MOVE_on,NULL,GSwitchToMoveMode,NULL);
	button_toggle(0,0,flag_ROTATE_on,flag_ROTATE,flag_ROTATE_on,flag_ROTATE_on,NULL,GSwitchToRotateMode,NULL);
	button_toggle(0,0,flag_SCALE_on,flag_SCALE,flag_SCALE_on,flag_SCALE_on,NULL,GSwitchToScaleMode,NULL);
	
	flags = OVERLAY;
}

PANEL *panMain_Bottom = {
	layer = 0;
	
	bmap = "panMain_Bottom.bmp";
	
	button(0,0,"home_on.png","home.png","home_on.png",NULL,GBackMenuShow,NULL);
	button(0,0,"objects_on.png","objects.png","objects_on.png",NULL,GInsertObjectShow,NULL);
	button(0,0,"pathing_on.png","pathing.png","pathing_on.png",NULL,GTerrainSubmenuShow,NULL);
	button(0,0,"flying_grass.png","flying_grass.png","flying_grass.png",NULL,GToggleObjectSeeder,NULL);
	
	flags = OVERLAY;
}

PANEL *panMain_Play = {
	layer = 0;
	
	bmap = "panMain_Play.bmp";
	
	button(0,0,"playtest_on.png","playtest.png","playtest_on.png",NULL,LoadPlayground,NULL);
	
	flags = OVERLAY;
}

PANEL *panLight = {
	
	layer = 2;
	
	bmap = "panLight.bmp";
	
	button(166,1,"button_close_on.bmp","button_close_off.bmp","button_close_over.bmp",NULL,GLightWindowHide,NULL);
	
	hslider(153,65,65,"slider.bmp",0,255,v_lred);
	hslider(153,87,65,"slider.bmp",0,255,v_lgreen);
	hslider(153,110,65,"slider.bmp",0,255,v_lblue);
	hslider(163,196,60,"slider.bmp",0,2000,v_lrange);
	
	button_toggle(105,260,flag_DISCO_on,flag_DISCO,flag_DISCO_on,flag_DISCO_on,NULL,NULL,NULL);
	button_toggle(105,280,flag_FLICK_on,flag_FLICK,flag_FLICK_on,flag_FLICK_on,NULL,NULL,NULL);
	
	on_click = GPanelDrag;
	
	flags = OVERLAY; // because of the checkboxes...
	
}

PANEL *panRotateHelp = {
	
	layer = 5;
	bmap = "panRotateHelp.png";
	
	flags = OVERLAY;
	
}

PANEL *panScaleHelp = {
	
	layer = 5;
	bmap = "panRotateHelp.png";
	
	flags = OVERLAY;
	
}

PANEL *MainMenu_Item1 = {
	
	layer = 2;
	
	bmap = "button_NewGame_off.bmp";
	button(0,0,"button_NewGame_on.bmp","button_NewGame_off.bmp","button_NewGame_on.bmp",NULL,GWorldNewShow,NULL);
	
	flags = OVERLAY | TRANSLUCENT;
	
	alpha = 75;
	
}

PANEL *MainMenu_Item2 = {
	
	layer = 2;
	
	bmap = "button_LoadGame_off.bmp";
	button(0,0,"button_LoadGame_on.bmp","button_LoadGame_off.bmp","button_LoadGame_on.bmp",NULL,GLoadGameShow,NULL);

	flags = OVERLAY | TRANSLUCENT;

	alpha = 75;

}

PANEL *MainMenu_Item3 = {
	
	layer = 2;
	
	bmap = "button_Options_off.bmp";
	button(0,0,"button_Options_on.bmp","button_Options_off.bmp","button_Options_on.bmp",NULL,GOptionsShow,NULL);
	
	flags = OVERLAY | TRANSLUCENT;

	alpha = 75;

}

PANEL *MainMenu_Item4 = {
	
	layer = 2;
	
	bmap = "button_Achievements_off.bmp";
	button(0,0,"button_Achievements_on.bmp","button_Achievements_off.bmp","button_Achievements_on.bmp",NULL,GTrophiesShow,NULL);
	
	flags = OVERLAY | TRANSLUCENT;

	alpha = 75;

}

PANEL *MainMenu_Item5 = {
	
	layer = 2;
	
	bmap = "button_Credits_off.bmp";
	button(0,0,"button_Credits_on.bmp","button_Credits_off.bmp","button_Credits_on.bmp",NULL,GCreditsShow,NULL);
	
	flags = OVERLAY | TRANSLUCENT;

	alpha = 75;

}

PANEL *MainMenu_Item6 = {
	
	layer = 2;
	
	bmap = "button_Help_on.bmp";
	button(0,0,"button_Help_on.bmp","button_Help_off.bmp","button_Help_on.bmp",NULL,GHelpShow,NULL);
	
	flags = OVERLAY | TRANSLUCENT;
	
	alpha = 75;
	
}

PANEL *panCAMRecorder = {
	
	layer = 3;
	bmap = "panCAMRecorder.bmp";
	
	flags = OVERLAY | TRANSLUCENT;
	
	alpha = 100;
	
}

PANEL *panCAMRecorder_digits = {
	
	layer = 4;
	digits(0,0,2,"Arial#25b",1,sys_seconds);
	digits(0,0,2,"Arial#25b",1,sys_minutes);	
	digits(0,0,2,"Arial#25b",1,sys_hours);
	
}

PANEL *panCAMRecorderREC = {
	
	pos_x = 10;
	pos_y = 10;
	
	layer = 4;
	bmap = "panCAMRecorderREC.bmp";
	
	flags = OVERLAY | TRANSLUCENT;
	
	alpha = 100;
	
}

PANEL *panScreenshot = {
	
	layer = 999;
	bmap = "panScreenshot.bmp";
	
	flags = TRANSLUCENT;
	alpha = 100;
	
}

////////////////////////////////////////////////////////////
// Materials will be defined here.
////////////////////////////////////////////////////////////
/*

MATERIAL *mat_smaragd = {
	ambient_red = 100;
	ambient_green = 255;
	ambient_blue = 100;
	diffuse_red = 0;
	diffuse_green = 100;
	diffuse_blue = 0;
	specular_red = 255;
	specular_green = 255;
	specular_blue = 255;
	power = 10;
}

MATERIAL *mat_lava = {
	emissive_red = 200;
	emissive_green = 70;
	emissive_blue = 20;
	ambient_red = 255;
	ambient_green = 150;
	ambient_blue = 50;
	diffuse_red = 200;
	diffuse_green = 150;
	diffuse_blue = 50;
	specular_red = 255;
	specular_green = 255;
	specular_blue = 255;
	alpha = 60;
	albedo = 70;
	power = 10;
}

MATERIAL *mat_marble = {
	emissive_red = 30;
	emissive_green = 30;
	emissive_blue = 30;
	ambient_red = 200;
	ambient_green = 225;
	ambient_blue = 200;
	diffuse_red = 255;
	diffuse_green = 255;
	diffuse_blue = 255;
	specular_red = 255;
	specular_green = 255;
	specular_blue = 255;
	power = 10;
}

MATERIAL *mat_lavenderrose = {
	
	ambient_red = 251;
	ambient_green = 160;
	ambient_blue = 227;
	
	power = 10;
	
}

MATERIAL *mat_bitterlemon = {
	
	ambient_red = 13;
	ambient_green = 224;
	ambient_blue = 202;
	
	power = 10;
	
}

MATERIAL *mat_peachorange = {
	
	ambient_red = 255;
	ambient_green = 204;
	ambient_blue = 153;
	
	power = 10;
	
}

MATERIAL *mat_purewhite = {
	
	ambient_red = 255;
	ambient_green = 255;
	ambient_blue = 255;
	emissive_red = 255;
	emissive_green = 255;
	emissive_blue = 255;
	diffuse_red = 255;
	diffuse_green = 255;
	diffuse_blue = 255;
	specular_red = 255;
	specular_green = 255;
	specular_blue = 255;
	
	power = 10;
	
}

MATERIAL *mat_black = {
	
	ambient_red = 0;
	ambient_green = 0;
	ambient_blue = 0;
	emissive_red = 0;
	emissive_green = 0;
	emissive_blue = 0;
	diffuse_red = 0;
	diffuse_green = 0;
	diffuse_blue = 0;
	specular_red = 0;
	specular_green = 0;
	specular_blue = 0;
	
	power = 0;
	
}

MATERIAL *mat_palelilac = {
	
	ambient_red = 255;
	ambient_green = 187;
	ambient_blue = 187;
	
	power = 10;
	
}

MATERIAL *mat_select = 
{
	ambient_red=255;
	ambient_green=255;
	ambient_blue=0;
	diffuse_red=255;
	diffuse_green=255;
	diffuse_blue=0;
}

*/

////////////////////////////////////////////////////////////
// Entities will be defined here.
////////////////////////////////////////////////////////////
/*

ENTITY *sky_horizon =
{ //this is needed to fix the bad 3dgs horizon merging
	type = "horizon.tga";
	layer = 10; 
	scale_x = 0.25;
	scale_y = 0.25;
	tilt = -60;//adjust this when you change sky_curve or sky_clip settings
	alpha = 100; 
	flags2 = SKY|SCENE;
	flags = TRANSLUCENT|PASSABLE;
}

ENTITY *sky_cloud1 =
{ 
	type = "clouds.tga";
	layer = 4;
	u = cloud1_speed_x; 
	v = cloud1_speed_y; 
	scale_y = cloud1_scale_x; 
	scale_x = cloud1_scale_y; 
	tilt = -12;//-6; 
	flags2 = SKY|DOME; 
	flags = TRANSLUCENT|PASSABLE;
	alpha = cloud1_alpha; 
} 

ENTITY *sky_cloud2 =
{ 
	type = "clouds.tga";
	layer = 6; 
	u = cloud2_speed_x; 
	v = cloud2_speed_y; 
	scale_x = cloud2_scale_x; 
	scale_y = cloud2_scale_y; 
	tilt = -10;//-5;
	flags2 = SKY|DOME; 
	flags = TRANSLUCENT|PASSABLE; 
	alpha = cloud2_alpha; 
}

//bad weather clouds
ENTITY *sky_cloud3 =
{ 
	type = "clouds_bad.tga";
	layer = 8;
	u = cloud3_speed_x; 
	v = cloud3_speed_y; 
	scale_x = cloud3_scale_x; 
	scale_y = cloud3_scale_y; 
	tilt = -10;//-5;
	flags2 = SKY|DOME;
	flags = TRANSLUCENT|PASSABLE; 
	alpha = 0;//cloud3_alpha; 
}
`

ENTITY *sky_day =
{ 
	type = "sky_day.tga";
	layer = 2;
	scale_x = 0.25;
	tilt = -20;//-10;
	red = sky_add_red;
	green = sky_add_green;
	blue = sky_add_blue;
	alpha = 60;//sky_alpha; 
	flags2 = SKY|SCENE; 
	flags = TRANSLUCENT|PASSABLE;
}

ENTITY *sky_sun =
{
	type = "sky_sun.tga";
	layer = 12;
	alpha = sun_alpha;
	flags2 = SKY;
	flags = TRANSLUCENT|PASSABLE|BRIGHT;
}

ENTITY *sky_suncorona =
{
	type = "sky_suncorona.tga";
	layer = 6;
	alpha = sun_corona_alpha;
	flags2 = SKY;
	flags = TRANSLUCENT|PASSABLE|BRIGHT;
}

ENTITY *sky_sunshine =
{
	type = "sky_sunshine.tga";
	layer = 14;
	alpha = sun_shine_alpha;
	flags2 = SKY;
	flags = TRANSLUCENT|PASSABLE|BRIGHT;
}

ENTITY *sky_night =
{ 
	type = "sky_night.tga";  
	layer = 2;
	alpha = 0;//night_sky_alpha; 
	flags2 = SKY|DOME; 
	flags = TRANSLUCENT|PASSABLE; 
} 

ENTITY *sky_moon =
{
	type = "sky_moon.tga";
	layer = 4;
	alpha = moon_alpha;
	flags2 = SKY;
	flags = TRANSLUCENT|PASSABLE;
}

ENTITY *flare1_ent =
{
	type = "lens_01.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare2_ent =
{
	type = "lens_02.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare4_ent =
{
	type = "lens_04.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare5_ent =
{
	type = "lens_05.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare6_ent =
{
	type = "lens_06.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare7_ent =
{
	type = "lens_07.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare8_ent =
{
	type = "lens_08.tga";
	view = camera;
	layer = 16;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare9_ent =
{
	type = "lens_09.tga";
	view = camera;
	layer = 16;
	scale_x = 2;
	scale_y = 2;
}
ENTITY *flare10_ent =
{
	type = "lens_10.tga";
	view = camera;
	layer = 16;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare11_ent =
{
	type = "lens_11.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare12_ent =
{
	type = "lens_12.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare13_ent =
{
	type = "lens_13.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare14_ent =
{
	type = "lens_14.tga";
	layer = 16;
	view = camera;	
	scale_x = 2.5;
	scale_y = 2.5;
}

ENTITY *flare15_ent =
{
	type = "lens_15.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare16_ent =
{
	type = "lens_16.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare17_ent =
{
	type = "lens_17.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare18_ent =
{
	type = "lens_18.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare19_ent =
{
	type = "lens_19.tga";
	layer = 16;
	view = camera;
	scale_x = 2;
	scale_y = 2;
}

ENTITY *flare20_ent =
{
	type = "lens_20.tga";
	layer = 16;
	view = camera;
	scale_x = 2.8;
	scale_y = 2.8;
}

*/

void GWeatherMode_RainOnly() { if( event_type == EVENT_RELEASE ) return; weather_rain(); if( nRandomWeather ) nRandomWeather = 0; }
void GWeatherMode_SnowOnly() { if( event_type == EVENT_RELEASE ) return; weather_snow(); if( nRandomWeather ) nRandomWeather = 0; }
void GWeatherMode_Nothing() { if( event_type == EVENT_RELEASE ) return; weather_sun();  if( nRandomWeather ) nRandomWeather = 0; }
void GWeatherMode_RainSnow() { if( event_type == EVENT_RELEASE ) return; nRandomWeather = 1; }

/* 
--------------------------------------------------
void GGPanelDrag(PANEL *p)

Desc:

If you have two panels that is attached to each other, with one 
(or both) is draggable, then make sure to update their positions 
after the while(mouse_left) loop.

Returns: -
--------------------------------------------------
*/
void GPanelDrag(PANEL *p)
{

	var click_offset[2];

	click_offset[0]=p.pos_x - mouse_pos.x;
	click_offset[1]=p.pos_y - mouse_pos.y;

	GPanelSelect(p);

	while(mouse_left)
	{
		proc_mode = PROC_EARLY;
		
		p.pos_x = mouse_pos.x+click_offset[0];
		p.pos_y = mouse_pos.y+click_offset[1];
		
		wait(1);
	}
	
	if(p == Stats) {
		
		StatsPanel->pos_x = Stats->pos_x + 266;
		StatsPanel->pos_y = Stats->pos_y + 66;
		
		
	}
}

/*
--------------------------------------------------
void GPanelCenter(PANEL *p)

Desc:

Returns: -
--------------------------------------------------
*/
void GPanelCenter(PANEL *p) {
	while(p == NULL) wait(1);

	p.pos_x = (screen_size.x - bmap_width(p.bmap)) / 2; 
	p.pos_y = (screen_size.y - bmap_height(p.bmap)) / 2;
}

/* 
--------------------------------------------------
void GPanelCenterInside(PANEL *p, PANEL *s)

Desc:

Returns: -
--------------------------------------------------
*/
void GPanelCenterInside(PANEL *p, PANEL *s) {
	while(p == NULL || s == NULL) wait(1);

	// peform a S comparison
	if(bmap_width(p.bmap)*bmap_height(p.bmap) > bmap_width(s.bmap)*bmap_height(s.bmap)) {
		
		return;
		
	}

	if(bmap_width(s.bmap) > bmap_width(p.bmap))
	p.pos_x = (bmap_width(s.bmap) - bmap_width(p.bmap))/2;

	if(bmap_height(s.bmap) > bmap_height(p.bmap))
	p.pos_y = (bmap_height(s.bmap) - bmap_height(p.bmap))/2;
}

/*
--------------------------------------------------
void GPanelRotate(PANEL *p,var lim,var speed,bool rotate_on_center)

Desc:

Returns: -
--------------------------------------------------
*/
void GPanelRotate(PANEL *p,var lim,var speed,bool rotate_on_center)
{
	while(p == NULL && !is(p,SHOW)) wait(1);
	
	if(rotate_on_center)
	{
		p->center_x = p->size_x * 0.5;
		p->center_y = p->size_y * 0.5;
	}
	while(p->angle < lim)
	{
		p->angle += speed * time_step;
		wait(1);
	}
	p->angle = 0; 
}

/*
--------------------------------------------------
void GPanelResize(PANEL *p, char c)

Desc:

Returns: -
--------------------------------------------------
*/
void GPanelResize(PANEL *p, int c) {
	
	while(p == NULL) wait(1);
	
	switch(c) {
		
		case RESIZE_X: p.scale_x = sys_metrics(0)/bmap_width(p.bmap); break;
		case RESIZE_Y: p.scale_y = sys_metrics(1)/bmap_height(p.bmap); break;
		
		case RESIZE_XY:
		
		p.scale_x = sys_metrics(0)/bmap_width(p.bmap);
		p.scale_y = sys_metrics(1)/bmap_height(p.bmap);
		
		break;
		
	}
	
}

/*
--------------------------------------------------
void GPanelAlignMainMenu(PANEL *Panel)

Desc:

Returns: -
--------------------------------------------------
*/
void GPanelAlignMainMenu(PANEL *Panel) {
	
	while(!Panel) wait(1);
	
	Panel.pos_x = (sys_metrics(0) - bmap_width(Panel.bmap)) / 2;
	Panel.pos_y = sys_metrics(1)/4 + bmap_height(MainMenu_Bar.bmap) * MainMenu_Bar.scale_y + BORDER;
	
}

/* 
--------------------------------------------------
void GGUIInit()

Desc:

Returns: -
--------------------------------------------------
*/
void GGUIInit() {
	
	wait(2);
	
	//layer_sort(Gun,panCAMRecorder->layer-1);
	
	GPanelResize(CreateWorld,RESIZE_XY);
	GPanelCenter(InsertObject);
	//	GPanelResize(seedPanelCover,RESIZE_XY);
	CreateWorldCoffee.pos_x = screen_size.x - bmap_width(CreateWorldCoffee.bmap) - BORDER * 2;
	CreateWorldCoffee.pos_y = screen_size.y - bmap_height(CreateWorldCoffee.bmap) - BORDER * 2;
	
	ReleaseInfo.pos_x = screen_size.x - str_width( (ReleaseInfo->pstring) [1], ReleaseInfo->font ) - BORDER * 2;
	ReleaseInfo.pos_y = screen_size.y - BORDER * 4;
	
	GPanelCenter(QuitDialog);
	GPanelCenter(panCAMRecorder); // x+y-scale
	GPanelResize(panScreenshot,RESIZE_XY);
	GPanelResize(BackMenu_Background,RESIZE_XY);
	GPanelCenter(FPCrosshair);
	GPanelCenter(InDev);
	GPanelCenter(panCAMRecorder);
	
	GPanelAlignMainMenu(NewGame_Screen1);
	GPanelAlignMainMenu(NewGame_ScreenDyn_Step1);
	GPanelAlignMainMenu(NewGame_ScreenStatic_Step1);
	
	//	GPanelCenter(NewGame_Screen1);
	//	NewGame_Screen1->pos_y += 5 * BORDER;
	//	NewGame_ScreenDyn_Step1->pos_y = NewGame_Screen1->pos_y;
	//	NewGame_ScreenStatic_Step1->pos_y = NewGame_ScreenDyn_Step1->pos_y;
	
	GPanelAlignMainMenu(NewGame_Screen3);
	GPanelAlignMainMenu(Options_Graphics);
	GPanelAlignMainMenu(Options_Sound);
	GPanelAlignMainMenu(Options_Themes);
	GPanelAlignMainMenu(Options_Maintenance);
	GPanelAlignMainMenu(LoadGame);
	
	NewGame_ScreenLeft.pos_x = NewGame_Screen1.pos_x - NewGame_Screen1.pos_x/2;
	NewGame_ScreenLeft.pos_y = NewGame_Screen1.pos_y + bmap_width(NewGame_Screen1.bmap)/4;
	
	NewGame_ScreenRight.pos_x = NewGame_ScreenLeft.pos_x + bmap_width(NewGame_Screen1.bmap) + (NewGame_Screen1.pos_x - NewGame_ScreenLeft.pos_x);
	NewGame_ScreenRight.pos_y = NewGame_ScreenLeft.pos_y;
	
	int i;
	for(i = 3;i > 0;i--) pan_setpos(panCAMRecorder_digits,1,i,vector(screen_size.x - 35 - 30 * i,BORDER,0));
	
	panMain_Top.pos_x = screen_size.x - 64 - (BORDER + 3 * 64);
	panMain_Top.pos_y = BORDER;

	panMain_Bottom.pos_x = BORDER;
	panMain_Bottom.pos_y = screen_size.y - 64 - BORDER;
	
	#ifdef A7_DEVELOPMENT
	// permanently disable the terrain seeding functionality
	BMAP *dummy_b = bmap_create("./Cooked2D/button_black.bmp");
	pan_setbutton( panMain_Bottom, 4, 1, 0, 0, dummy_b, dummy_b, dummy_b, dummy_b, dummy, dummy, dummy );
	#endif

	panRotateHelp.pos_x = screen_size.x - bmap_width(panRotateHelp.bmap) - BORDER * 2;
	panRotateHelp.pos_y = panMain_Top.pos_y + BORDER * 2;

	panScaleHelp.pos_x = screen_size.x - bmap_width(panScaleHelp.bmap) - BORDER * 2;
	panScaleHelp.pos_y = panRotateHelp.pos_y;
	int i = 1;
	while(i < 7) {
		pan_setpos(panMain_Top,3,i,vector((i - 1) * (BORDER + 64),0,0));
		i++;
	}

	int i = 1;
	while(i < 6) {
		pan_setpos(panMain_Bottom,3,i,vector((i-1) * (BORDER + 64),0,0));
		
		i++;
	}
	
	/*
	
	Options_Graphics.pos_y =
	Options_Sound.pos_y = 
	Options_Themes.pos_y = 
	Options_Maintenance.pos_y =
	(screen_size.y - bmap_height(Options_Graphics.bmap)) / 2;
	
	Options_Graphics.pos_x =
	Options_Sound.pos_x = 
	Options_Themes.pos_x = 
	Options_Maintenance.pos_x =
	screen_size.x - bmap_width(Options_Graphics.bmap) - BORDER*3;
	
	*/
	
	MusicPlayer.pos_x = screen_size.x - bmap_width ( MusicPlayer.bmap ) - BORDER * 2;
	MusicPlayer.pos_y = screen_size.y - BORDER * 8 - bmap_height(MusicPlayer.bmap) ;
	
	TerrainToolbar.pos_y = screen_size.y - BORDER * 10 - bmap_height(TerrainToolbar.bmap);
	TerrainToolbar.pos_x = BORDER;
	
	MainMenu_Bar.pos_x = 0;
	MainMenu_Bar.pos_y = screen_size.y/4;
	
	MainMenu_Bar.scale_x = sys_metrics(0)/bmap_width(MainMenu_Bar.bmap);
	MainMenu_Bar.scale_y = .5;
	
	MainMenu_Item1.pos_y  = MainMenu_Item2.pos_y = MainMenu_Item3.pos_y = MainMenu_Item4.pos_y = MainMenu_Item5.pos_y = MainMenu_Item6.pos_y = MainMenu_Bar.pos_y + BORDER/2;
	MainMenu_Item1.pos_x = BORDER;
	MainMenu_Item2.pos_x = MainMenu_Item1.pos_x + bmap_width(MainMenu_Item1.bmap) + BORDER;
	MainMenu_Item3.pos_x = MainMenu_Item2.pos_x + bmap_width(MainMenu_Item2.bmap) + BORDER;
	MainMenu_Item4.pos_x = MainMenu_Item3.pos_x + bmap_width(MainMenu_Item3.bmap) + BORDER;
	MainMenu_Item5.pos_x = MainMenu_Item4.pos_x + bmap_width(MainMenu_Item4.bmap) + BORDER;
	MainMenu_Item6.pos_x = MainMenu_Item5.pos_x + bmap_width(MainMenu_Item5.bmap) + BORDER;

	panMain_Play.pos_x = screen_size.x - BORDER - bmap_width(panMain_Play.bmap);
	panMain_Play.pos_y = screen_size.y - BORDER - bmap_height(panMain_Play.bmap);
	
	OptionsGraphicsTxt = txt_create(10,500);
	OptionsSoundTxt = txt_create(10,500);
	OptionsThemesTxt = txt_create(10,500);
	OptionsMaintenanceTxt = txt_create(10,500);
	
	OptionsGraphicsTxt->font = OptionsSoundTxt->font = OptionsThemesTxt->font = OptionsMaintenanceTxt->font = font_create("Arial#19");
	
	InputBox_GROUNDSTR.pos_x = NewGame_Screen3.pos_x + 45;
	InputBox_GROUNDSTR.pos_y = NewGame_Screen3.pos_y + 140;
	
	InputBox_SKYSTR.pos_x = NewGame_Screen3.pos_x + 450;
	InputBox_SKYSTR.pos_y = InputBox_GROUNDSTR.pos_y;
	
	InputBox_LOADGAMESTR.pos_x = LoadGame.pos_x + 35;
	InputBox_LOADGAMESTR.pos_y = LoadGame.pos_y + 110;
	
	files_list_SKYSTR.pos_x = InputBox_SKYSTR.pos_x;
	files_list_SKYSTR.pos_y = InputBox_SKYSTR.pos_y;
	
	files_list_GROUNDSTR.pos_x = InputBox_GROUNDSTR.pos_x;
	files_list_GROUNDSTR.pos_y = InputBox_GROUNDSTR.pos_y;
	
	files_list_LOADGAMESTR.pos_x = InputBox_LOADGAMESTR.pos_x;
	files_list_LOADGAMESTR.pos_y = InputBox_LOADGAMESTR.pos_y;
	
	NewGame_PreviewButton.pos_x = (screen_size.x - bmap_width(NewGame_PreviewButton.bmap))/2;
	NewGame_PreviewButton.pos_y = 50;
	
}

/* 
--------------------------------------------------
void GPanelSelect(PANEL *p)

Desc:

Returns: -
--------------------------------------------------
*/
void GPanelSelect(PANEL *p)
{
	
	if(last_pan) {
		
		last_pan.alpha = DEFAULT_ALPHA;
		layer_sort(last_pan,2);
		
		last_pan = p;
		layer_sort(last_pan,4);
		last_pan.alpha = 100;
		
	}
	
	else {
		
		last_pan = p;
		layer_sort(last_pan,4);
		last_pan.alpha = 100;
		
	}
}

/* 
--------------------------------------------------
void GTerrainSubmenuShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GTerrainSubmenuShow() {
	
	if(event_type == EVENT_RELEASE) return;
	
	GToggleTerrainEditor();
	
}

/*
--------------------------------------------------
void GToggleTerrainEditor()

Desc:

Returns: -
--------------------------------------------------
*/
void GToggleTerrainEditor() {
	
	if(event_type == EVENT_RELEASE) return;
	
	if( !is(TerrainToolbar,SHOW) ) {
		
		if(is(InsertObject, SHOW) ) GInsertObjectHide();
		if( is(seedPanelCover,SHOW) ) GToggleObjectSeeder();
		
		set(TerrainToolbar,SHOW);
		cbTerrainEditing = 1;
		
		button_state(TerrainToolbar,1,1);
		
		if(marker) Scale(marker, SCALE_MARKER_TERRAIN);
		
		
	}
	else {
		
		cbTerrainEditing = 0;
		reset(TerrainToolbar,SHOW);
		
		if(marker) Scale(marker, SCALE_MARKER );
		////		
		////		if(mark) GInsertObjectShow();
		
		return;
		
	}
	
	while( cbTerrainEditing ) {
		
		if(bSize<0) bSize=0;
		//		if(sizeh<0) sizeh=0;
		
		if(key_shift) bSize += mickey.z/20*50*time_step;
		
		//un-comment the lines to unlock desired features
		//		if(key_ctrl) sizeh +=mickey.z/200*time_step;
		//		if(key_alt) tMaxHeight +=mickey.z/20*time_step;
		
		wait(1);
		
	}
	
}

/*
--------------------------------------------------
void GToggleObjectSeeder( )

Desc:

Returns: -
--------------------------------------------------
*/
void GToggleObjectSeeder( ) {
	
	if(event_type == EVENT_RELEASE) return;
	
	if( is(TerrainToolbar,SHOW) ) GToggleTerrainEditor();
	if(is(InsertObject,SHOW) ) GInsertObjectHide();
	
	var old_from_test_play = from_test_play;
	int j = 0, k = -1;
	
	BMAP *olmouse_map = mouse_map;
	mouse_map = mouse_painttex;
	
	// Simple test to see if there's a mask before
	TEXT *simple = txt_create(100, 1);
	int i = txt_for_dir( simple ,"./Cooked2D/Masks/*.tga");
	
	if( i ) {
		
		for(;j<i;j++) {
			
			if( str_stri( ( simple.pstring )[j], SEEDMASKDATA) ) {
				
				k = j;
				
				// found the right j, now load it
				canvas_paint = bmap_create ( (simple.pstring)[j] );
				while(proc_status(bmap_create) ) wait(1);
				
				canvas_pan.bmap = canvas_paint;
				
				GPanelCenter(canvas_pan);
				while(proc_status(GPanelCenter)) wait(1);
				canvas_pan->pos_y += 100;
				
				pan_setbutton(canvas_pan,0,0,0,0,canvas_paint,canvas_paint,canvas_paint,canvas_paint,paint_canvas,NULL,NULL);
				while(proc_status(pan_setbutton)) wait(1);
				
				set(canvas_pan, SHOW);
				set(seedPanelCover,SHOW);
				
				j=i+1; // Force the loop to exit
				
			}
			
		}
	}
	
	if( k != -1 && TerrainEnt ) { // The other case, I don't use !k here because...it could be 0, which can cause bug.
		
		bmap_savetga( ent_getskin(TerrainEnt,1), "./Cooked2D/Masks/tskin.tga");
		while( proc_status(bmap_savetga) ) wait(1);
		
		// canvas_paint = ent_getskin(TerrainEnt,1);
		canvas_paint = bmap_create("./Cooked2D/Masks/tskin.tga");
		canvas_pan.bmap = canvas_paint;
		//		GPanelResize(canvas_pan,RESIZE_XY); // <- It could cause bug
		GPanelCenter(canvas_pan);
		canvas_pan->pos_y += 100;
		canvas_pan->pos_x = 10;
		
		pan_setbutton(canvas_pan,0,0,0,0,canvas_paint,canvas_paint,canvas_paint,canvas_paint,paint_canvas,NULL,NULL);
		set(canvas_pan, SHOW);
		set(seedPanelCover,SHOW);
		//		set(color_picker,SHOW);
		//		set(pencils_pan,SHOW);
		
	}
	
	while( is(canvas_pan,SHOW) ) {
		
		if(mouse_panel != canvas_pan) paint_outside = 1;
		else paint_outside = 0;

		coords_x = mouse_cursor.x - canvas_pan.pos_x;
		coords_y = mouse_cursor.y - canvas_pan.pos_y;
		
		wait(1);
		
	}
	
	reset(canvas_pan,SHOW);
	reset(seedPanelCover,SHOW);
	mouse_map = olmouse_map;
	//	reset(color_picker,SHOW);
	//	reset(pencils_pan,SHOW);
	
	from_test_play = old_from_test_play;
}

/*
--------------------------------------------------
void GTerrainLoadGeoWrapper()

Desc:

Returns: -
--------------------------------------------------
*/
void GTerrainLoadGeoWrapper() {
	
	if(event_type == EVENT_RELEASE) return;
	
	TDeform_LoadHeightFrom(TerrainEnt);
	
}

/*
--------------------------------------------------
void GTerrainSaveGeoWrapper()

Desc:

Returns: -
--------------------------------------------------
*/
void GTerrainSaveGeoWrapper() {
	
	if(event_type == EVENT_RELEASE) return;
	
	TDeform_saveterrain(TerrainEnt);
	
}

/*
--------------------------------------------------
void GGUIHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GGUIHide() {
	
	if(select) {
		
		// Deselect any selected entity first
		if(select.ObjectType == Light) GLightWindowHide();
		if(select.ObjectType == Object) GPropertiesWindowHide();
		if(select.ObjectType == Sound) GSoundWindowHide();
		if(select.ObjectType == Particle) GParticleWindowHide();
		
		//		select.material = mat_temp;
		select = NULL;
		
	}

	reset(panMain_Top,SHOW);
	reset(panMain_Bottom,SHOW);
	reset(panMain_Play,SHOW);

	// Also disables any remaining active content.
	reset(panRotateHelp,SHOW);
	reset(panScaleHelp,SHOW);
	
	if( is(InsertObject,SHOW) ) GInsertObjectHide();
	if( is(TerrainToolbar,SHOW) ) GToggleTerrainEditor();
	if( is(seedPanelCover,SHOW) ) GToggleObjectSeeder();
	
}

/*
--------------------------------------------------
void GGUIShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GGUIShow() {

	set(panMain_Top,SHOW);
	set(panMain_Bottom,SHOW);
	set(panMain_Play,SHOW);

}

/*
--------------------------------------------------
void GMaterialEditorShow()

Desc:

Returns: -
--------------------------------------------------
*/

/*

void GMaterialEditorShow() {
	
	if(event_type == EVENT_RELEASE) return;

	// Precache panMat_Sub1
	GGUIUpdate(panMat_Sub1);

	// Material editor is available only to custom materials
	switch(mat_type) {
		
		case select_custom_mat1 :
		
		PassMaterialDataToWindow(mat_custom[0]);
		set(panMat_Sub1,SHOW);
		
		GPanelSelect(panMat_Sub1);
		
		break;
		//////////////////////////////////////////////////////////////
		
		case select_custom_mat2 :
		
		PassMaterialDataToWindow(mat_custom[1]);
		set(panMat_Sub1,SHOW);
		
		GPanelSelect(panMat_Sub1);
		
		break;
		//////////////////////////////////////////////////////////////
		
		case select_custom_mat3 :
		
		PassMaterialDataToWindow(mat_custom[2]);
		set(panMat_Sub1,SHOW);
		
		GPanelSelect(panMat_Sub1);
		
		break;
		//////////////////////////////////////////////////////////////
		
		case select_custom_mat4 :
		
		PassMaterialDataToWindow(mat_custom[3]);
		set(panMat_Sub1,SHOW);
		
		GPanelSelect(panMat_Sub1);
		
		break;
		//////////////////////////////////////////////////////////////
		
		default:
		printf("Material editor is available only to custom materials.");
		break;
	}	
}

*/

// stupid switchers
// lite-C compiler: stupid programmer

/*
--------------------------------------------------
void GSwitchToMoveMode()

Desc:

Returns: -
--------------------------------------------------
*/
void GSwitchToMoveMode() {
	
	if(event_type == EVENT_RELEASE) return;
	
	//	if(!is(ZTool,SHOW)) set(ZTool,SHOW);

	// Check its state first.
	if(button_state(panMain_Top,1,-1)) {
		
		button_state(panMain_Top,2,0);
		button_state(panMain_Top,3,0);
		
		// Switch to ' object move ' state.
		manip_type = move;
		
		//		reset(panRotateHelp,SHOW);
		//		reset(panScaleHelp,SHOW);
		
	}

	else {
		
		// The loop can't check this so nothing will be assigned
		// to manip_type.
		manip_type = scale+1;
		
		//		if(is(ZTool,SHOW)) reset(ZTool,SHOW);
		
	}
}

/*
--------------------------------------------------
void GSwitchToRotateMode()

Desc:

Returns: -
--------------------------------------------------
*/
void GSwitchToRotateMode() {
	
	if(event_type == EVENT_RELEASE) return;
	
	//	if(!is(ZTool,SHOW)) set(ZTool,SHOW);

	if(button_state(panMain_Top,2,-1)) {
		
		button_state(panMain_Top,1,0);
		button_state(panMain_Top,3,0);
		
		manip_type = rotate;
		
		//		set(panRotateHelp,SHOW);
		//		reset(panScaleHelp,SHOW);
		
	}

	else {
		
		manip_type = scale+1;
		
		//		reset(panRotateHelp,SHOW);
		//		if(is(ZTool,SHOW)) reset(ZTool,SHOW);
		
	}
}

/*
--------------------------------------------------
void GSwitchToScaleMode()

Desc:

Returns: -
--------------------------------------------------
*/
void GSwitchToScaleMode() {
	
	if(event_type == EVENT_RELEASE) return;
	
	//	if(!is(ZTool,SHOW)) set(ZTool,SHOW);

	if(button_state(panMain_Top,3,-1)) {
		
		button_state(panMain_Top,1,0);
		button_state(panMain_Top,2,0);
		
		manip_type = scale;
		
		//		reset(panRotateHelp,SHOW);
		//		set(panScaleHelp,SHOW);
		
	}

	else {
		
		manip_type=scale+1;
		
		//		reset(panScaleHelp,SHOW);
		//		if(is(ZTool,SHOW)) reset(ZTool,SHOW);
		
	}

}

/*
--------------------------------------------------
void GNotificationCreate(FONT *f, STRING *r)

Desc:

Returns: -
--------------------------------------------------
*/
void GNotificationCreate(FONT *f, STRING *r)
{
	proc_kill(4);

	TEXT *rt = txt_create(1,1);

	rt->font = f;
	str_cpy((rt.pstring)[0],r);

	rt->pos_x = screen_size.x -  str_width((rt.pstring)[0],f) - BORDER - 30; // -30 because I'm using the free edition.
	rt->pos_y = BORDER;

	set(rt,SHOW);

	// It's supposed to be "while(Game Is Running) wait(1);"
	// but I haven't added into the game yet.
	while(1) wait(1);
	
	reset(rt,SHOW);
	str_remove((rt.pstring)[0]);
	txt_remove(rt);
}

/*
--------------------------------------------------
void GCreditsShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GCreditsShow() {
	
	if(event_type == EVENT_RELEASE) return;
	if(proc_status(GCreditsShow)) return;
	
	if( ! file_exists(FILE_CREDITS_TEXT) ) ExitEvent();
	
	var rollspeed = 3.5;
	
	
	
	//	reset(panNewGame,SHOW);
	GMainMenuHide();
	GWorldNewHide();
	GLoadGameHide();
	GOptionsHide();
	GHelpHide();
	GTrophiesHide();
	
	//	level_load(NULL);
	
	TEXT *import = txt_create(CREDITS_ROLL_MAXSTR,1);
	
	import.font = font_create("Arial#25b");
	
	txt_loadw(import,FILE_CREDITS_TEXT);
	
	import.pos_x = 15;
	import.pos_y = screen_size.y + BORDER;
	import.flags |= (SHADOW | FILTER/* | CENTER_X*/ );
	
	set(import,SHOW);
	
	while(!key_esc) {
		
		import.pos_y -= rollspeed * time_step;
		
		//		if(key_cuu) rollspeed = 4; else rollspeed = .5;
		//		if(key_cud) rollspeed = -4; else rollspeed = .5;
		
		wait(1);
		
	}
	
	reset(import,SHOW);
	
	int i = 0;
	for(;i<CREDITS_ROLL_MAXSTR;i++) str_remove((import.pstring)[i]); txt_remove(import);
	
	GMainMenuShow();	
	//	GLoadMainMenu();
	
}

/*
--------------------------------------------------
void GPanelSizeForWH(PANEL *p, BMAP *b)

Desc: Just a small function for use within GObjectTypeSwitcher(var).
Updates the size of p according to b's size.

Returns: -
--------------------------------------------------
*/
void GPanelSizeForWH(PANEL *p, BMAP *b) {
	while(b == NULL || p == NULL) wait(1);

	p.size_x = bmap_width(b);
	p.size_y = bmap_height(b);

}

/*
--------------------------------------------------
void GMainMenuShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GMainMenuShow() {
	
	set(MainMenu_Bar,SHOW);
	set(MainMenu_Item1,SHOW);
	set(MainMenu_Item2,SHOW);
	set(MainMenu_Item3,SHOW);
	set(MainMenu_Item4,SHOW);
	set(MainMenu_Item5,SHOW);
	set(MainMenu_Item6,SHOW);
	
	set(ReleaseInfo,SHOW);
	
	guiCurrentViewPreset = MENU_CAMERA_LAUNCH;
	
}

/*
--------------------------------------------------
void GMainMenuHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GMainMenuHide() {
	
	reset(MainMenu_Bar,SHOW);
	reset(MainMenu_Item1,SHOW);
	reset(MainMenu_Item2,SHOW);
	reset(MainMenu_Item3,SHOW);
	reset(MainMenu_Item4,SHOW);
	reset(MainMenu_Item5,SHOW);
	reset(MainMenu_Item6,SHOW);
	
	reset(ReleaseInfo,SHOW);
	
}

void GQuitDialogToggle() {
	
	if(event_type == EVENT_RELEASE) return;
	
	int temp_campos;
	
	while( !cbInBuildment ) {
		
		if(key_esc)  {
			
			while(key_esc) wait(1);
			
			/*
			if( !is(QuitDialog,SHOW) ) {
				
				GMainMenuHide();
				set(QuitDialog,SHOW);
				
				temp_campos = guiCurrentViewPreset;
				guiCurrentViewPreset = MENU_CAMERA_EXIT;
				
				
				} else {
				
				reset(QuitDialog,SHOW);
				GMainMenuShow(); 
				
				guiCurrentViewPreset = temp_campos;
				
			}
			*/
			
		}
		
		
		wait(1);
		
	}
}

/*
--------------------------------------------------
void GLoadMainMenu()

Desc:

Returns: -
--------------------------------------------------
*/
void GLoadMainMenu() {
	
	cbInBuildment = false;
	str_cpy(SKYSTR,undef);
	
	GGUIHide();
	GMainMenuShow();
	//	GPanelCenter(panMMenu);
	
	level_load( "./CookedWorlds/background.wmb"  );
	
	// Personalized settings for the main menu.
	camera->ambient = 75;
	
	//	level_load(NULL);
	//	game_load(pref_savebmaps,0);
	
	//	GPanelSelect(panMMenu);
	
	//	panMMenu.alpha = 50;
	
	guiViewPreset(&guiCurrentViewPreset, MENU_CAMERA_LAUNCH, MENU_CAMERA_LAUNCH_pos, MENU_CAMERA_LAUNCH_ang );
	guiViewPreset(&guiCurrentViewPreset, MENU_CAMERA_NEW_GAME, MENU_CAMERA_NEW_GAME_pos, MENU_CAMERA_NEW_GAME_ang );
	guiViewPreset(&guiCurrentViewPreset, MENU_CAMERA_LOAD_GAME, MENU_CAMERA_LOAD_GAME_pos, MENU_CAMERA_LOAD_GAME_ang );
	guiViewPreset(&guiCurrentViewPreset, MENU_CAMERA_HELP, MENU_CAMERA_HELP_pos, MENU_CAMERA_HELP_ang);
	guiViewPreset(&guiCurrentViewPreset, MENU_CAMERA_TROPHIES, MENU_CAMERA_TROPHIES_pos, MENU_CAMERA_TROPHIES_ang);
	guiViewPreset(&guiCurrentViewPreset, MENU_CAMERA_LAUNCH_GAME, MENU_CAMERA_LAUNCH_GAME_pos, MENU_CAMERA_LAUNCH_GAME_ang);
	guiViewPreset(&guiCurrentViewPreset, MENU_CAMERA_EXIT, MENU_CAMERA_EXIT_pos, MENU_CAMERA_EXIT_ang );
	
	GQuitDialogToggle();
	
}

/*
--------------------------------------------------
void GOptionsShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GOptionsShow() {
	
	if(event_type == EVENT_RELEASE) return;
	
	if(InMenu_Options) {
		
		GOptionsHide();
		
		return;
		
	}
	
	//	
	
	////	guiCurrentViewPreset = ;
	
	GWorldNewHide();
	GLoadGameHide();
	GHelpHide();
	GTrophiesHide();
	
	GOptions_Graphics();
	
	InMenu_Options = 1;
	
}

/*
--------------------------------------------------
void GOptionsHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GOptionsHide() {
	
	if(is(Options_Graphics,SHOW)) {
		
		reset(Options_Graphics,SHOW);
		reset(OptionsGraphicsTxt,SHOW);
		
	}
	
	if(is(Options_Sound,SHOW)) {
		
		reset(Options_Sound,SHOW);
		reset(OptionsSoundTxt,SHOW);
		
	}
	
	if(is(Options_Themes,SHOW)) {
		
		reset(Options_Themes,SHOW);
		
	}
	
	if(is(Options_Maintenance,SHOW)) {
		
		reset(Options_Maintenance,SHOW);
		
	}
	
	InMenu_Options = 0;
	
	return;
	
}

/*
--------------------------------------------------
void GPropertiesWindowShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GPropertiesWindowShow() {
	
	if(select) {
		
		if(select.ObjectType != Light &&
		select.ObjectType != Sound &&
		select.ObjectType != Particle) {
			
			set(panProp,SHOW);
			GPanelSelect(panProp);	
			
			//			GGUIUpdate(panProp);
			
		}
		
	}
	
}

/*
--------------------------------------------------
void GPropertiesWindowHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GPropertiesWindowHide() {
	
	if ( event_type == EVENT_RELEASE ) return;
	
	// Object is deactivated/other object has been selected.
	
	//	if(is(panMat_Sub1,SHOW)) reset(panMat_Sub1,SHOW);
	reset(panProp,SHOW);
	
}

/*
--------------------------------------------------
void GSoundWindowShow() 

Desc:

Returns: -
--------------------------------------------------
*/
void GSoundWindowShow() {
	
	set(panSnd,SHOW);
	
	GPanelSelect(panSnd);
	
}

/*
--------------------------------------------------
void GSoundWindowHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GSoundWindowHide() {
	
	if( event_type == EVENT_RELEASE ) return;
	
	reset(panSnd,SHOW);
	
}

/*
--------------------------------------------------
void GParticleWindowShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GParticleWindowShow() {
	
	set(panParticle,SHOW);
	
}

/*
--------------------------------------------------
void GParticleWindowHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GParticleWindowHide() {
	
	if( event_type == EVENT_RELEASE ) return;
	
	reset(panParticle,SHOW);
	
}

/*
--------------------------------------------------
void GLightWindowShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GLightWindowShow() {
	
	set(panLight,SHOW);
	
	GPanelSelect(panLight);
	
	// Surely, select has been selected already.
	
	v_lred = select.red;
	v_lgreen = select.green;
	v_lblue = select.blue;
	v_lrange = select.lightrange;
	
	// 'cause no#1 is the close button so we start from 2.
	if(select.LightMode == Disco) button_state(panLight,2,1);
	if(select.LightMode == Flick) button_state(panLight,3,1);
	
}

/*
--------------------------------------------------
void GLightWindowHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GLightWindowHide() {
	
	if( event_type == EVENT_RELEASE ) return;
	
	// For passing to loop_kernel without messing up the code 
	// and/or write a new one.
	if(!select) return; 
	
	// Apply new values to the selected object.
	select.red = v_lred;
	select.green = v_lgreen;
	select.blue = v_lblue;
	
	// I grouped.
	// Assignment will happen this way: A <-- B <-- C
	// So we obtain C first, in this case is v_lrange
	olrange = select.lightrange = v_lrange;
	
	if(button_state(panLight,2,-1)) select.LightMode = Disco;
	if(button_state(panLight,3,-1)) select.LightMode = Flick;
	
	reset(panLight,SHOW);
	
}

/* 
--------------------------------------------------
void GWorldNewShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GWorldNewShow() {
	
	if(event_type == EVENT_RELEASE) return;
	
	if(InMenu_NewGame) {
		
		GWorldNewHide();
		
		return;
		
	}
	
	guiCurrentViewPreset = MENU_CAMERA_NEW_GAME;
	
	GLoadGameHide();
	GOptionsHide();
	GTrophiesHide();
	GHelpHide();
	
	//	set(NewGame_ScreenLeft,SHOW);
	//	set(NewGame_ScreenRight,SHOW);
	set(NewGame_Screen1,SHOW);
	
	// Set default values
	int i = 1;
	for(; i<5;i++) button_state(NewGame_ScreenDyn_Step1,i,1);
	
	InMenu_NewGame = 1;
	
	while(InMenu_NewGame) {
		
		if( is(NewGame_ScreenDyn_Step1,SHOW) || ( is(NewGame_Screen3,SHOW) && WorldType == WORLD_DYNAMIC) ) {
			
			MoonScaleFactor = _MoonScaleFactor;
			NightDuration = _NightDuration;
			DayDuration = _DayDuration;
			NightSkySpeed = _NightSkySpeed;
			NightScaleFactor = _NightScaleFactor;
			
			Scale( entSkyMoon, _MoonScaleFactor );
			Scale( entSkyNight, _NightScaleFactor );
			
			if(is(NewGame_ScreenDyn_Step1,SHOW)) {
				
				_load_lensflare = button_state(NewGame_ScreenDyn_Step1,1,-1);
				_use_sun = button_state(NewGame_ScreenDyn_Step1,2,-1);
				_use_moon = button_state(NewGame_ScreenDyn_Step1,3,-1);
				_use_nightstars = button_state(NewGame_ScreenDyn_Step1,4,-1);
				
			}	
			
		}
		
		if( is(NewGame_ScreenStatic_Step1,SHOW) || ( is(NewGame_Screen3,SHOW) && WorldType == WORLD_STATIC) ) {
			
			_fog_color = fog_color = button_state(NewGame_ScreenStatic_Step1,1,-1);
			sun_light = _sun_light;
			d3d_fogcolor1.red = _d3d_fogcolor1_red;
			d3d_fogcolor1.green = _d3d_fogcolor1_green;
			d3d_fogcolor1.blue = _d3d_fogcolor1_blue;
			camera.fog_end = _camera_fog_end;
			
			/*
			
			//		   Uncomment the following lines to get the variable fog effect ;)
			//		   the panel will update its values very slow though.
			
			d3d_fogcolor1.red = random(255); wait(-1);
			d3d_fogcolor1.green = random(255); wait(-1);
			d3d_fogcolor1.blue = random(255); wait(-1);
			
			*/
			
		}
		
		wait(1);
		
	}
	
	reset(NewGame_Screen1,SHOW);
	reset(NewGame_Screen3,SHOW);
	reset(NewGame_ScreenLeft,SHOW);
	reset(NewGame_ScreenRight,SHOW);
	reset(NewGame_ScreenStatic_Step1,SHOW);
	reset(NewGame_ScreenDyn_Step1,SHOW);
	reset(InputBox_GROUNDSTR,SHOW);
	reset(InputBox_SKYSTR,SHOW);
	
	/*
	
	if(!is(panNewGame,SHOW)) {
		
		GGUIUpdate(panNewGame);
		GPanelCenter(panNewGame);
		
		set(panNewGame,SHOW);
		
		GPanelSelect(panNewGame); // Bring me to the TOP ! =))
		
		// Set some default parameters
		
		GToggleLevelCreationMode(2);
		button_state(panNewGame,2,1); // Static sky by default
		
		v_fogdensity = 3000; // Make fog_end a bit larger
		v_fogr = v_fogg = v_fogb = (var)255/2;
		
		_moon_scale_fac = moon_scale_fac;
		_time_speed_night = time_speed_night;
		_night_sky_scale_x = night_sky_scale_x;
		_night_sky_speed_x = night_sky_speed_x;
		
		//		button_state (panNewGame,5,1); // Lensflare on by default
		//		button_state (panNewGame,7,1); // Moon too
	}
	
	*/
	
}

/*
--------------------------------------------------
void GNewGameResetDynamicSettings()

Desc: 

Returns: -
--------------------------------------------------
*/
void GNewGameResetDynamicSettings() { wait(1);
	
	//		moon_scale_fac = original_moon_scale_fac;
	//		time_speed_night = original_time_speed_night;
	//		night_sky_scale_x = original_night_sky_scale_x;
	//		night_sky_speed_x = original_night_sky_speed_x;
	//		fog_color = original_fog_color;
	//		camera->fog_start = original_camera_fog_start;
	//		camera->fog_end = original_camera_fog_end;
	
}

/*
--------------------------------------------------
void GNewGameResetStaticSettings()

Desc:

Returns: -
--------------------------------------------------
*/
void GNewGameResetStaticSettings() { wait(1);
	
	//		fog_color = original_fog_color;
	//		d3d_fogcolor1.red = original_d3d_fogcolor1r;
	//		d3d_fogcolor1.green = original_d3d_fogcolor1g;
	//		d3d_fogcolor1.blue = original_d3d_fogcolor1b;
	//		sun_light = original_sun_light;
	
}

/*
--------------------------------------------------
void GWorldNewHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GWorldNewHide() {
	
	//	reset(panNewGame,SHOW);
	reset(files_list_GROUNDSTR,SHOW);
	reset(files_list_SKYSTR,SHOW);
	reset(NewGame_PreviewButton,SHOW);
	
	InMenu_NewGame = 0;
	LoadMystymood( false );
	
	if(WorldType == WORLD_DYNAMIC) GNewGameResetDynamicSettings();
	else GNewGameResetStaticSettings();
	
}

/*
--------------------------------------------------
void GIO_ObjectTab_SwitchTab(var ID)

Desc:

Returns: -
--------------------------------------------------
*/
void GIO_ObjectTab_SwitchTab(var ID) {
	
	if(event_type == EVENT_RELEASE) return;
	
	int _ID = ID, i;
	
	if(!button_state(IO_ObjectTab,_ID,-1)) {
		
		reset(files_list_TEMPSTR,SHOW);
		reset(InsertObject_Inputter,SHOW);
		
		FolderScan(files_list_TEMPSTR,"./","empty"); // Empty scan
		
		return;
		
	}
	
	else {
		
		if(!is(files_list_TEMPSTR,SHOW)) set(files_list_TEMPSTR,SHOW);
		if(!is(InsertObject_Inputter,SHOW)) set(InsertObject_Inputter,SHOW);
		
		switch(_ID) {
			
			// Animals
			case 1:
			
			for(i = 2;i <= 8;i++) button_state(IO_ObjectTab,i,0);
			
			FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_ANMS,EXT_OBJECT);
			
			break;
			
			// Architectures
			case 2:
			
			for(i = _ID-1;i >= 1;i--) button_state(IO_ObjectTab,i,0);
			for(i = _ID+1;i <= 8;i++) button_state(IO_ObjectTab,i,0);
			
			FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_ARCHS,EXT_OBJECT);
			
			break;
			
			// Characters
			case 3:

			for(i = _ID-1;i >= 1;i--) button_state(IO_ObjectTab,i,0);
			for(i = _ID+1;i <= 8;i++) button_state(IO_ObjectTab,i,0);
			
			FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_CHARS,EXT_OBJECT);   
			
			break;
			
			// Everyday objects
			case 4:
			
			for(i = _ID-1;i >= 1;i--) button_state(IO_ObjectTab,i,0);
			for(i = _ID+1;i <= 8;i++) button_state(IO_ObjectTab,i,0);
			
			FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_ETC,EXT_OBJECT);
			
			break;
			
			// Food
			case 5:
			
			for(i = _ID-1;i >= 1;i--) button_state(IO_ObjectTab,i,0);
			for(i = _ID+1;i <= 8;i++) button_state(IO_ObjectTab,i,0);
			
			FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_FOOD,EXT_OBJECT);
			
			break;
			
			// Machines
			case 6:
			
			for(i = _ID-1;i >= 1;i--) button_state(IO_ObjectTab,i,0);
			for(i = _ID+1;i <= 8;i++) button_state(IO_ObjectTab,i,0);
			
			FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_MACHS,EXT_OBJECT); 
			
			break;
			
			// Plants
			case 7:
			
			for(i = ID-1;i >= 1;i--) button_state(IO_ObjectTab,i,0);
			for(i = ID+1;i <= 8;i++) button_state(IO_ObjectTab,i,0);
			
			FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_PLANTS,EXT_OBJECT);
			
			break;
			
			// Transports
			case 8:
			
			for(i = _ID-1;i >= 1;i--) button_state(IO_ObjectTab,i,0);
			
			FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_TPORTTS,EXT_OBJECT); 
			
			break;
			
		}
		
		TEMPSTR_Scaler = 0;
		FillFromPool(files_list_TEMPSTR, files_list_TEMPSTR_Pool , 20, TEMPSTR_Scaler);
		
	}
	
}

/*
--------------------------------------------------
void GObjectTypeTab_Switcher(var ID)

Desc:

Returns: -
--------------------------------------------------
*/
void GObjectTypeTab_Switcher(var ID) {
	
	if(event_type == EVENT_RELEASE) return;
	
	int _ID;
	for(_ID = 2;_ID <= 9;_ID++) button_state(InsertObject,_ID,0);
	
	button_state(InsertObject,(int)ID,1);
	
	switch( (int)ID ) {
		
		case 1: // Object
		
		if(!is(IO_ObjectTab,SHOW)) set(IO_ObjectTab,SHOW);
		if(!is(files_list_TEMPSTR,SHOW)) set(files_list_TEMPSTR,SHOW);
		if(!is(InsertObject_Inputter,SHOW)) set(InsertObject_Inputter,SHOW);
		if(!is(IO_ObjectTab,SHOW)) set(IO_ObjectTab,SHOW);
		if(is(LightPresets,SHOW)) reset(LightPresets,SHOW);
		if(is(InsertParticle,SHOW)) reset(InsertParticle,SHOW);
		if(is(InsertSystemObjects,SHOW)) reset(InsertSystemObjects,SHOW);
		
		FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_ANMS,EXT_OBJECT);
		
		break;
		
		case 2: // Sound
		
		if(is(IO_ObjectTab,SHOW)) reset(IO_ObjectTab,SHOW);
		if(!is(files_list_TEMPSTR,SHOW)) set(files_list_TEMPSTR,SHOW);
		if(!is(InsertObject_Inputter,SHOW)) set(InsertObject_Inputter,SHOW);
		if(is(IO_ObjectTab,SHOW)) set(IO_ObjectTab,SHOW);
		if(is(LightPresets,SHOW)) reset(LightPresets,SHOW);
		if(is(InsertParticle,SHOW)) reset(InsertParticle,SHOW);
		if(is(InsertSystemObjects,SHOW)) reset(InsertSystemObjects,SHOW);
		
		FolderScan(files_list_TEMPSTR_Pool,PATH_SOUNDS,EXT_SOUND);
		
		break;
		
		case 3: // Particle
		
		if(is(IO_ObjectTab,SHOW)) reset(IO_ObjectTab,SHOW);
		if(is(files_list_TEMPSTR,SHOW)) reset(files_list_TEMPSTR,SHOW);
		if(is(InsertObject_Inputter,SHOW)) reset(InsertObject_Inputter,SHOW);
		if(is(IO_ObjectTab,SHOW)) reset(IO_ObjectTab,SHOW);
		if(is(LightPresets,SHOW)) reset(LightPresets,SHOW);
		if(is(InsertSystemObjects,SHOW)) reset(InsertSystemObjects,SHOW);
		if(!is(InsertParticle,SHOW)) set(InsertParticle,SHOW);
		
		break;
		
		case 4: // Light
		
		if(is(IO_ObjectTab,SHOW)) reset(IO_ObjectTab,SHOW);
		if(is(files_list_TEMPSTR,SHOW)) reset(files_list_TEMPSTR,SHOW);
		if(is(InsertObject_Inputter,SHOW)) reset(InsertObject_Inputter,SHOW);
		if(is(IO_ObjectTab,SHOW)) reset(IO_ObjectTab,SHOW);
		if(!is(LightPresets,SHOW)) set(LightPresets,SHOW);
		if(is(InsertParticle,SHOW)) reset(InsertParticle,SHOW);
		if(is(InsertSystemObjects,SHOW)) reset(InsertSystemObjects,SHOW);
		
		break;
		
		case 5: // Sprite
		
		if(!is(IO_ObjectTab,SHOW)) set(IO_ObjectTab,SHOW);
		if(!is(files_list_TEMPSTR,SHOW)) set(files_list_TEMPSTR,SHOW);
		if(!is(InsertObject_Inputter,SHOW)) set(InsertObject_Inputter,SHOW);
		if(is(IO_ObjectTab,SHOW)) reset(IO_ObjectTab,SHOW);
		if(is(LightPresets,SHOW)) reset(LightPresets,SHOW);
		if(is(InsertParticle,SHOW)) reset(InsertParticle,SHOW);
		if(is(InsertSystemObjects,SHOW)) reset(InsertSystemObjects,SHOW);
		
		FolderScan(files_list_TEMPSTR_Pool,PATH_SPRITES,EXT_SPRITE);
		
		break;
		
		//		case 6: // Terrain
		//		
		//		if(!is(IO_ObjectTab,SHOW)) set(IO_ObjectTab,SHOW);
		//		if(!is(files_list_TEMPSTR,SHOW)) set(files_list_TEMPSTR,SHOW);
		//		if(!is(InsertObject_Inputter,SHOW)) set(InsertObject_Inputter,SHOW);
		//		if(is(IO_ObjectTab,SHOW)) reset(IO_ObjectTab,SHOW);
		//		if(is(LightPresets,SHOW)) reset(LightPresets,SHOW);
		//		if(is(InsertParticle,SHOW)) reset(InsertParticle,SHOW);
		//		if(is(InsertSystemObjects,SHOW)) reset(InsertSystemObjects,SHOW);
		//		
		//		FolderScan(files_list_TEMPSTR_Pool,PATH_TERRAINS,EXT_TERRAIN);
		
		case 6: // Event triggers
		
		if(is(IO_ObjectTab,SHOW)) reset(IO_ObjectTab,SHOW);
		if(is(files_list_TEMPSTR,SHOW)) reset(files_list_TEMPSTR,SHOW);
		if(is(InsertObject_Inputter,SHOW)) reset(InsertObject_Inputter,SHOW);
		if(is(IO_ObjectTab,SHOW)) reset(IO_ObjectTab,SHOW);
		if(is(LightPresets,SHOW)) reset(LightPresets,SHOW);
		if(is(InsertParticle,SHOW)) reset(InsertParticle,SHOW);
		if(!is(InsertSystemObjects,SHOW)) set(InsertSystemObjects,SHOW);
		
		break;
		
		case 8: // world blocks (minecraft style)
		
		break;
	}
	
	TEMPSTR_Scaler = 0;
	FillFromPool(files_list_TEMPSTR,files_list_TEMPSTR_Pool,20,TEMPSTR_Scaler);
	
}

/*
--------------------------------------------------
void GInsertObjectShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GInsertObjectShow() {
	
	if(event_type == EVENT_RELEASE) return;
	
	if(is(InsertObject,SHOW)) GInsertObjectHide();
	if( is(TerrainToolbar,SHOW) ) GToggleTerrainEditor();
	if( is(seedPanelCover,SHOW) ) GToggleObjectSeeder();
	
	InsertObject->alpha = 0;
	set(InsertObject,SHOW);
	
	while(InsertObject->alpha <= 75) {
		
		InsertObject->alpha += 25 * time_step;
		wait(1);
		
	}		
	set(IO_ObjectTab,SHOW);
	set(InsertObject_Inputter,SHOW);
	set(InsertObject,SHOW);
	
	int i;
	for(i = 2;i<=8;i++) button_state(IO_ObjectTab,i,0);
	for(i = 3;i<=7;i++) button_state(InsertObject,i,0);
	
	button_state(IO_ObjectTab,1,1);
	button_state(InsertObject,2,1);
	
	set(files_list_TEMPSTR,SHOW);
	
	layer_sort(files_list_TEMPSTR,50);
	layer_sort(InsertObject_Inputter,100);
	
	FolderScan(files_list_TEMPSTR_Pool,PATH_OBJECTS_ANMS,EXT_OBJECT);
	FillFromPool(files_list_TEMPSTR, files_list_TEMPSTR_Pool, 20, TEMPSTR_Scaler);
	
	//	while(is(InsertObject,SHOW)) {
		
		IO_ObjectTab.pos_x = InsertObject.pos_x + 25;
		IO_ObjectTab.pos_y = InsertObject.pos_y + 250;
		
		files_list_TEMPSTR.pos_x = InsertObject.pos_x + 200;
		files_list_TEMPSTR.pos_y = InsertObject.pos_y + 100;
		
		InsertObject_Inputter.pos_x = files_list_TEMPSTR.pos_x;
		InsertObject_Inputter.pos_y = files_list_TEMPSTR.pos_y;
		
		LightPresets.pos_x = InsertObject.pos_x + 100;
		LightPresets.pos_y = InsertObject.pos_y + 100;
		
		InsertParticle.pos_x = InsertObject.pos_x + 100;
		InsertParticle.pos_y = InsertObject.pos_y + 100;
		
		InsertSystemObjects.pos_x = InsertObject.pos_x + 100;
		InsertSystemObjects.pos_y = InsertObject.pos_y + 100;
		
		
		//		wait(1);
		//		
	//	}
	
	//	if(mark) GToggleTerrainEditor(); // flip the switch again
	
}

/*
--------------------------------------------------
void GInsertObjectHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GInsertObjectHide() {
	
	if(event_type == EVENT_RELEASE) return;
	
	reset(InsertObject,SHOW);
	reset(InsertObject,SHOW);
	reset(IO_ObjectTab,SHOW);
	reset(InsertObject_Inputter,SHOW);
	reset(LightPresets,SHOW);
	reset(InsertParticle,SHOW);
	reset(InsertSystemObjects,SHOW);
	
	reset(files_list_TEMPSTR,SHOW);
	
}

/*
--------------------------------------------------
void GSelectObject(var ID)

Desc:

Returns: -
--------------------------------------------------
*/
void GSelectObject(var ID) {
	
	if(event_type == EVENT_RELEASE) return;
	
	int _ID = ID-1;
	
	if( str_cmp( (files_list_TEMPSTR.pstring)[_ID],undef) )  {
		
		str_cpy(TEMPSTR,undef);
		
		_beep();
		return;
		
	}
	
	if(is(InsertObject,SHOW)) {
		
		if(is(IO_ObjectTab,SHOW) )
		{
			
			while( !is(files_list_TEMPSTR,SHOW) && !is(InsertObject_Inputter,SHOW) ) wait(1);
			
			/* Can't split them - TEMPSTR will be overwritten. */
			
			if(button_state(IO_ObjectTab,1,-1)) { // anms
				
				str_cpy(TEMPSTR,PATH_OBJECTS_ANMS);
				TEMP_OBJECT_TYPE = ObjectAnimal;
				
			}
			
			if(button_state(IO_ObjectTab,2,-1)) { // archs
				
				str_cpy(TEMPSTR,PATH_OBJECTS_ARCHS);
				TEMP_OBJECT_TYPE = ObjectArchitecture;
				
			}
			
			if(button_state(IO_ObjectTab,3,-1)) { // chars
				
				str_cpy(TEMPSTR,PATH_OBJECTS_CHARS);
				TEMP_OBJECT_TYPE = ObjectCharacter;
				
			}
			
			if(button_state(IO_ObjectTab,4,-1)) { // everyday/etc
				
				str_cpy(TEMPSTR,PATH_OBJECTS_ETC);
				TEMP_OBJECT_TYPE = ObjectEveryday;
				
			}
			
			if(button_state(IO_ObjectTab,5,-1)) { // food
				
				str_cpy(TEMPSTR,PATH_OBJECTS_FOOD);
				TEMP_OBJECT_TYPE = ObjectFood;
				
			}
			
			if(button_state(IO_ObjectTab,6,-1)) { // machs
				
				str_cpy(TEMPSTR,PATH_OBJECTS_MACHS);
				TEMP_OBJECT_TYPE = ObjectMachine;
				
			}
			
			if(button_state(IO_ObjectTab,7,-1)) { // plants
				
				str_cpy(TEMPSTR,PATH_OBJECTS_PLANTS);
				TEMP_OBJECT_TYPE = ObjectPlant;
				
			}
			
			if(button_state(IO_ObjectTab,8,-1)) { // transports
				
				str_cpy(TEMPSTR,PATH_OBJECTS_TPORTTS);
				TEMP_OBJECT_TYPE = ObjectTransport;
				
			}
			
			
			str_cat(TEMPSTR,(files_list_TEMPSTR.pstring)[_ID]);
			
			//			LoadPreview			();			
			
			GInsertObjectHide();
			SystemObjectID = -1;
			//			create();
			
			mark_seedEntstr = 1;
			
			return;
			
		} 
		
		if(button_state(InsertObject,2,-1)) { // Sound
			
			str_cpy(TEMPSTR,PATH_SOUNDS);
			str_cat(TEMPSTR,(files_list_TEMPSTR.pstring)[_ID]);
			TEMP_OBJECT_TYPE = Sound;
			
			GInsertObjectHide();
			SystemObjectID = -1;
			
			return;
			
		}
		
		if(button_state(InsertObject,5,-1)) { // Sprite
			
			str_cpy(TEMPSTR,PATH_SPRITES);
			str_cat(TEMPSTR,(files_list_TEMPSTR.pstring)[_ID]);
			TEMP_OBJECT_TYPE = Sprite;
			
			GInsertObjectHide();
			SystemObjectID = -1;
			
			return;
			
		}
		
		/*
		
		if(button_state(InsertObject,7,-1)) { // Terrain
			
			str_cpy(TEMPSTR,PATH_TERRAINS);
			str_cat(TEMPSTR,(files_list_TEMPSTR.pstring)[_ID]);
			TEMP_OBJECT_TYPE = Terrain;
			
			GInsertObjectHide();
			
			return;
			
		}
		
		*/
		
	}
	
}

/*
--------------------------------------------------
void GSelectParticle(var ID)

Desc:

Returns: -
--------------------------------------------------
*/
void GSelectParticle(var ID) {
	
	if(event_type == EVENT_RELEASE) return;
	
	switch((int)ID) {
		
		case 1: ParticleIDNumber = part_spiral; break;
		case 2: ParticleIDNumber = part_colorfulspark; break;
		case 3: ParticleIDNumber = part_spacehole; break;
		case 4: ParticleIDNumber = part_fountain2; break;
		case 5: ParticleIDNumber = part_fountain1; break;
		case 6: ParticleIDNumber = part_fire2; break;
		case 7: ParticleIDNumber = part_fire1; break;
		case 8: ParticleIDNumber = part_doublehelix; break;
		case 9: ParticleIDNumber = part_composition; break;
		
	}

	TEMP_OBJECT_TYPE = Particle;
	GInsertObjectHide();
	
}

/*
--------------------------------------------------
void GSelectLight(var ID)

Desc:

Returns: -
--------------------------------------------------
*/
void GSelectLight(var ID) {
	
	if(event_type == EVENT_RELEASE) return;
	
	switch((int)ID) {
		
		case 1:
		// RGB color code for Pure Red
		// temp_light = CopyColor(255,0,0);
		temp_light.red = 255;
		temp_light.green = 0;
		temp_light.blue = 0;
		
		break;
		
		case 2:
		// RGB color code for Pure Green
		// temp_light = CopyColor(0,255,0);
		temp_light.red = 0;
		temp_light.green = 255;
		temp_light.blue = 0;
		
		break;
		
		case 3:
		// RGB color code for Pure Yellow
		/* 
		@en.wikipedia.org
		On a computer display, yellow is created by combining green and red light at the right intensity on a black screen.
		This is called the RGB color model.
		
		So red + green = yellow
		*/
		// temp_light = CopyColor(255,255,0);
		temp_light.red = 255;
		temp_light.green = 255;
		temp_light.blue = 0;
		
		break;
		
		case 4:
		// RGB color code for Teal from http://en.wikipedia.org/wiki/Teal
		// temp_light = CopyColor(54,117,136);
		temp_light.red = 54;
		temp_light.green = 117;
		temp_light.blue = 136;
		
		break;
		
		case 5:
		// RGB color code for Bud Green from http://en.wikipedia.org/wiki/List_of_colors:_A%E2%80%93F
		// Bonus: May Green, (76, 145, 65).
		// temp_light = CopyColor(123,182,97);
		temp_light.red = 123;
		temp_light.green = 182;
		temp_light.blue = 97;
		
		break;
		
		case 6:
		// RGB color code for Pure White
		// temp_light = CopyColor(255,255,255);
		temp_light.red = temp_light.green = temp_light.blue = 255;
		
		break;
		
		case 7:
		// RGB color code for Cyan from http://en.wikipedia.org/wiki/Cyan
		// green + blue = cyan
		// temp_light = CopyColor(0,255,255);
		temp_light.red = 0;
		temp_light.green = 255;
		temp_light.blue = 255;		
		break;
		
		case 8:
		// RGB color code for Pure Orange from http://en.wikipedia.org/wiki/Orange_(colour)
		/*
		@en.wikipedia.org
		
		In the RGB colour model, the system used to create colours on a television or computer 
		screen, orange is made by combining high intensity red light 
		with a lower intensity green light, and the blue light turned off.
		
		*/
		// temp_light = CopyColor(255,127,0);
		temp_light.red = 255;
		temp_light.green = 127;
		temp_light.blue = 0;
		
		break;
		
		case 9:
		// RGB color code for Violet from http://en.wikipedia.org/wiki/Violet_(color)
		/*
		@en.wikipedia.org
		violet is simulated by purple, by combining blue light at high intensity with a less intense red light on a black screen. 
		The range of purples is created by combining blue and red light of any intensities; the chromaticities formed this way line along the "line of purples".
		*/
		// temp_light = CopyColor(143,0,255);
		temp_light.red = 143;
		temp_light.green = 0;
		temp_light.blue = 255;
		
		break;
		
		case 10:
		// RGB color code for Lavender from http://en.wikipedia.org/wiki/Lavender_(color)
		// temp_light = CopyColor(230,230,250);
		temp_light.red = 230;
		temp_light.green = 230;
		temp_light.blue = 250;
		
		break;
		
		case 11:
		// RGB color code for Brown from http://en.wikipedia.org/wiki/Brown
		// temp_light = CopyColor(150,75,0);
		temp_light.red = 150;
		temp_light.green = 75;
		temp_light.blue = 0;
		
		break;
		
		case 12:
		// RGB color code for Indigo from http://en.wikipedia.org/wiki/Indigo
		/*
		@en.wikipedia.org
		
		The color electric indigo is a bright and saturated color between the traditional indigo and violet. 
		This is the brightest color indigo that can be approximated on a computer screen[citation needed]�it is a color located between the (primary) blue and the color violet on the RGB color wheel.
		*/
		// temp_light = CopyColor(75,0,130);
		temp_light.red = 75;
		temp_light.green = 0;
		temp_light.blue = 130;
		
		break;
		
		// Add more color cases here, just make sure you put more buttons.
		
		
	}
	
	TEMP_OBJECT_TYPE = Light;
	GInsertObjectHide();
	
}

/*
--------------------------------------------------
void GPreMainMenu()

Desc:

Returns: -
--------------------------------------------------
*/

/*

void GPreMainMenu() {
	
	randomize();
	
	// Let's roll a dice
	int i = random(5); // 6 backgrounds
	
	switch(i) {
		
		case 0: BackgroundScreen.bmap = BackgroundScreen1; break;
		case 1: BackgroundScreen.bmap = BackgroundScreen2; break;
		case 2: BackgroundScreen.bmap = BackgroundScreen3; break;
		case 3: BackgroundScreen.bmap = BackgroundScreen4; break;
		case 4: BackgroundScreen.bmap = BackgroundScreen5; break;
		case 5: BackgroundScreen.bmap = BackgroundScreen6; break;
		
	}
	
	GPanelResize(BackgroundScreen,RESIZE_XY);
	
	set(BackgroundScreen,SHOW);
	set(PreMainMenuLoading,SHOW);
	
}

*/

// Sorry for the terrible-lookin' code. I don't have much time.
/*
--------------------------------------------------
void GOptions_Graphics()

Desc:

Returns: -
--------------------------------------------------
*/
void GOptions_Graphics() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(is(Options_Sound,SHOW)) {
		
		reset(Options_Sound,SHOW);
		reset(OptionsSoundTxt,SHOW);
		
	}
	if(is(Options_Themes,SHOW)) reset(Options_Themes,SHOW);
	if(is(Options_Maintenance,SHOW)) reset(Options_Maintenance,SHOW);
	
	// Reflect settings from defaultConfig struct to GUI
	
	button_state(Options_Graphics,11,defaultConfig._SSAO); // 11  SSAO
	button_state(Options_Graphics,12,defaultConfig.HDR); // 12  HDR
	button_state(Options_Graphics,13,defaultConfig.DOF); // 13  DOF
	button_state(Options_Graphics,14,defaultConfig.Shadows); // 14  Shadows
	button_state(Options_Graphics,15,defaultConfig.ObjShaders); // 15  Object-based shaders
	button_state(Options_Graphics,16,defaultConfig.PPE); // Post Process effects
	
	/*
	
	tempConfig = CreateGraphicsStruct(
	
	defaultConfig.Brightness,
	defaultConfig.BitDepth,
	defaultConfig.AFLevel,
	defaultConfig.AALevel,
	defaultConfig._SSAO,
	defaultConfig.DOF,
	defaultConfig.HDR,
	defaultConfig.Shadows,
	defaultConfig.ObjShaders,
	defaultConfig.PPE
	
	);
	
	*/
	
	set(Options_Graphics, SHOW);
	set(OptionsGraphicsTxt,SHOW);
	
	OptionsGraphicsTxt.pos_x = Options_Graphics.pos_x + 290;
	OptionsGraphicsTxt.pos_y = Options_Graphics.pos_y + 90;
	
	//layer_sort(OptionsGraphicsTxt,Options.layer+2);
	
	// Test for fullscreen
	switch(video_screen) {
		
		case 1: // Fullscreen
		str_cpy((OptionsGraphicsTxt.pstring)[0],"Full Screen");
		
		break;
		
		case 2: // Windowed
		str_cpy((OptionsGraphicsTxt.pstring)[0],"Windowed");
		
		break;
		
	}
	
	// Test for widescreen
	
	// Floating values can't be tested using switch..case.
	
	/*
	
	if(video_aspect >= 4/3 && video_aspect < 16/10) str_cpy((OptionsGraphicsTxt.pstring)[1],"4:3");
	else if(video_aspect >= 16/10 && video_aspect < 16/9) str_cpy((OptionsGraphicsTxt.pstring)[1],"16:10");
	else if(video_aspect >= 16/9) str_cpy((OptionsGraphicsTxt.pstring)[1],"16:9");
	else str_cpy((OptionsGraphicsTxt.pstring)[1],"I don't know...");	
	
	*/
	
	// Test for bit depth
	
	switch(video_depth) {
		
		case 16:
		str_cpy((OptionsGraphicsTxt.pstring)[2],"16-bit");
		
		break;
		
		case 32:
		str_cpy((OptionsGraphicsTxt.pstring)[2],"32-bit");
		
		break;
		
	}
	
	// Brightness
	str_cpy((OptionsGraphicsTxt.pstring)[3],str_create(str_for_num((OptionsGraphicsTxt.pstring)[3],video_gamma)));
	
	// FSAA
	str_cpy((OptionsGraphicsTxt.pstring)[4],str_create(str_for_num((OptionsGraphicsTxt.pstring)[4],d3d_antialias)));
	
	// Anisotropic filtering
	str_cpy((OptionsGraphicsTxt.pstring)[5],str_create(str_for_num((OptionsGraphicsTxt.pstring)[5],d3d_anisotropy)));
	
	
}

/*
--------------------------------------------------
void GOptions_Sound()

Desc:

Returns: -
--------------------------------------------------
*/
void GOptions_Sound() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(is(Options_Graphics,SHOW)) {
		
		reset(Options_Graphics, SHOW);
		reset(OptionsGraphicsTxt,SHOW);
		
		
	}
	
	if(is(Options_Themes,SHOW)) reset(Options_Themes,SHOW);
	if(is(Options_Maintenance,SHOW)) reset(Options_Maintenance,SHOW);

	set(Options_Sound,SHOW);
	set(OptionsSoundTxt,SHOW);
	
	OptionsSoundTxt.pos_x = Options_Sound.pos_x + 290;
	OptionsSoundTxt.pos_y = Options_Sound.pos_y + 90;
	
	// Music volume
	str_cpy((OptionsSoundTxt.pstring)[0],str_create(str_for_num((OptionsSoundTxt.pstring)[0],VOL_MUSIC)));
	
	// Effects volume
	str_cpy((OptionsSoundTxt.pstring)[1],str_create(str_for_num((OptionsSoundTxt.pstring)[1],VOL_EFFECTS)));
	
	// Doppler effect
	str_cpy((OptionsSoundTxt.pstring)[2],str_create(str_for_num((OptionsSoundTxt.pstring)[2],doppler_factor)));
}

/*
--------------------------------------------------
void GOptions_Themes()

Desc:

Returns: -
--------------------------------------------------
*/
void GOptions_Themes() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(is(Options_Graphics,SHOW)) {
		
		reset(Options_Graphics, SHOW);
		reset(OptionsGraphicsTxt,SHOW);
		
	}
	
	if(is(Options_Sound,SHOW)) {
		
		reset(Options_Sound,SHOW);
		reset(OptionsSoundTxt,SHOW);
		
	}
	
	reset(Options_Maintenance,SHOW);
	
	set(Options_Themes,SHOW);
	
	//	GInDevShow();
	
}

/*
--------------------------------------------------
void GOptions_Maintenance()

Desc:

Returns: -
--------------------------------------------------
*/
void GOptions_Maintenance() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(is(Options_Graphics,SHOW)) {
		
		reset(Options_Graphics, SHOW);
		reset(OptionsGraphicsTxt,SHOW);
		
	}
	
	if(is(Options_Sound,SHOW)) {
		
		reset(Options_Sound,SHOW);
		reset(OptionsSoundTxt,SHOW);
		
	}
	
	reset(Options_Themes,SHOW);
	
	set(Options_Maintenance,SHOW);
	
	//	GInDevShow();
	
}

/*
--------------------------------------------------
void GOptions_SaveSettings()

Desc:

Returns: -
--------------------------------------------------
*/
void GOptions_SaveSettings() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	//	int temporary_BitDepth;
	
	if(is(Options_Graphics,SHOW)) {
		
		// Compare the third pstring for bit depth
		if(str_cmp((OptionsGraphicsTxt.pstring)[2],"16-bit")) video_set(0,0,16,0);
		else video_set(0,0,32,0);
		
		if( str_cmp((OptionsGraphicsTxt.pstring)[0],"Full Screen") ) {
			
			// 'cause WIDTH and HEIGHT aren't defined globally
			// just for testing when loading the kernel
			// so sys_metrics is directly used here.
			
			// depth always 0  
			video_set(sys_metrics(0),sys_metrics(1),0,1);
			
		}
		else video_set(sys_metrics(0),sys_metrics(1),0,2);
		
		// Check for wide screen, gamma, fsaa, aa and so.
		/*
		
		if( str_cmp((OptionsGraphicsTxt.pstring)[1],"4:3") ) video_aspect = 4/3;
		else if(str_cmp((OptionsGraphicsTxt.pstring)[1],"16:9")) video_aspect = 16/9;
		else video_aspect = 16/10;
		
		*/
		
		defaultConfig.Brightness = str_to_num( (OptionsGraphicsTxt.pstring) [3] );
		defaultConfig.AALevel = str_to_num( (OptionsGraphicsTxt.pstring) [4] );
		defaultConfig.AFLevel = str_to_num( (OptionsGraphicsTxt.pstring) [5] );
		defaultConfig._SSAO = button_state(Options_Graphics,11,-1); // 11 = SSAO
		defaultConfig.HDR = button_state(Options_Graphics,12,-1); // 12 = HDR
		defaultConfig.DOF = button_state(Options_Graphics,13,-1); // 13 = DOF
		defaultConfig.Shadows = button_state(Options_Graphics,14,-1); // 14 = Shadows
		defaultConfig.ObjShaders = button_state(Options_Graphics,15,-1); // 15 = Object-based shaders
		defaultConfig.PPE = button_state(Options_Graphics,16,-1); // Post Process effects
		wait(2);
			
		GOptionsHide();
		
		return;
		
	}

	if(is(Options_Sound,SHOW)) {
		
		VOL_MUSIC = str_to_num( (OptionsSoundTxt.pstring) [0] );
		VOL_EFFECTS = str_to_num( (OptionsSoundTxt.pstring) [1] );
		doppler_factor = str_to_num( (OptionsSoundTxt.pstring) [2] );
		
		GOptionsHide();
		
		return;
		
	}

	if(is(Options_Themes,SHOW)) {
		
		GOptionsHide();
		
		return;
		
	}

	if(is(Options_Maintenance,SHOW)) {
		
		GOptionsHide();
		
		return;
		
	}
	
}

/*
--------------------------------------------------
void GOptionsAdjustSettings(var ID)

Desc:

Returns: -
--------------------------------------------------
*/
void GOptionsAdjustSettings(var ID) {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(is(Options_Graphics,SHOW)) {
		
		ID = (int)ID; // Well, I have nothing to say...
		
		switch(ID) {
			
			case 1: case 2: // Full screen <-> Windowed
			
			if( str_cmp((OptionsGraphicsTxt.pstring)[0],"Full Screen") ) str_cpy((OptionsGraphicsTxt.pstring)[0],str_create("Windowed"));
			else str_cpy((OptionsGraphicsTxt.pstring)[0],str_create("Full Screen"));
			
			break;
			
			/*
			
			case 3: case 4: // 4:3 <-> 16:10 <-> 16:9
			
			if( str_cmp((OptionsGraphicsTxt.pstring)[1],"4:3") ) str_cpy( (OptionsGraphicsTxt.pstring) [1] , str_create("16:9"));
			else if ( str_cmp((OptionsGraphicsTxt.pstring)[1],"16:9")) str_cpy( (OptionsGraphicsTxt.pstring) [1] , str_create("16:10"));
			else str_cpy( (OptionsGraphicsTxt.pstring) [1] , str_create("4:3"));
			
			break;
			
			*/
			
			case 3: case 4: // 16-bit color depth <-> 32-bit
			
			if( str_cmp((OptionsGraphicsTxt.pstring)[2],"16-bit") ) str_cpy( (OptionsGraphicsTxt.pstring) [2],str_create("32-bit"));
			else str_cpy( (OptionsGraphicsTxt.pstring) [2],str_create("16-bit"));
			
			break;
			
			case 5: // Brightness --
			
			int brightness = str_to_num( (OptionsGraphicsTxt.pstring) [3]);
			
			if(brightness <= 50) break;
			
			brightness-=5;
			
			str_for_num((OptionsGraphicsTxt.pstring)[3],brightness);
			
			break;
			
			case 6: // brightness ++
			
			int brightness = str_to_num( (OptionsGraphicsTxt.pstring) [3]);
			brightness+=5;
			
			if (brightness >= 150) break;
			
			str_for_num((OptionsGraphicsTxt.pstring)[3],brightness);
			
			break;
			
			case 7: // fsaa --
			
			int fsaa = str_to_num( (OptionsGraphicsTxt.pstring) [4]);
			
			if(fsaa <= 0) break;
			
			fsaa--;
			
			str_for_num((OptionsGraphicsTxt.pstring)[4],fsaa);
			
			break;
			
			case 8: // fsaa ++ 
			
			int fsaa = str_to_num( (OptionsGraphicsTxt.pstring) [4]);
			
			if(fsaa >= 9) break;
			fsaa++;
			
			str_for_num((OptionsGraphicsTxt.pstring)[4],fsaa);
			
			break;
			
			case 9: // af --
			
			int af = str_to_num( (OptionsGraphicsTxt.pstring) [5]);
			
			if(af <= 0) break;
			af--;
			
			str_for_num((OptionsGraphicsTxt.pstring)[5],af);
			
			break;
			
			case 10: // af ++ 
			
			int af = str_to_num( (OptionsGraphicsTxt.pstring) [5]);
			
			if(af >= 7) break;
			af++;
			
			str_for_num((OptionsGraphicsTxt.pstring)[5],af);
			
			break;
			
		}	
		
		return ;
		
	}
	
	if(is(Options_Sound,SHOW)) {
		
		switch(ID) {
			
			case 1: // Music volume --
			
			var mv = str_to_num((OptionsSoundTxt.pstring)[0]);
			if(mv <= 0) break;
			mv-=5;
			
			str_for_num((OptionsSoundTxt.pstring)[0],mv);
			
			break;
			
			case 2: // Music volume ++
			
			var mv = str_to_num((OptionsSoundTxt.pstring)[0]);
			if(mv >= 100) break;
			mv+=5;
			
			str_for_num((OptionsSoundTxt.pstring)[0],mv);
			
			break;
			
			case 3: // Sound volume -- 
			
			var sv = str_to_num((OptionsSoundTxt.pstring)[1]);
			if(sv <= 0) break;
			sv-=5;
			
			str_for_num((OptionsSoundTxt.pstring)[1],sv);
			
			break;
			
			case 4: // Sound volume ++ 
			
			var sv = str_to_num((OptionsSoundTxt.pstring)[1]);
			if(sv >= 100) break;
			sv+=5;
			
			str_for_num((OptionsSoundTxt.pstring)[1],sv);
			
			break;
			
			case 5: // Doppler --
			
			int doppler = str_to_num((OptionsSoundTxt.pstring)[2]);
			if(doppler <= 0) break;
			doppler--;
			
			str_for_num((OptionsSoundTxt.pstring)[2],doppler);
			
			break;
			
			case 6: // Doppler ++
			
			int doppler = str_to_num((OptionsSoundTxt.pstring)[2]);
			if(doppler >= 10) break;
			doppler++;
			
			str_for_num((OptionsSoundTxt.pstring)[2],doppler);
			
			break;
			
		}
		
		return;
		
	}
	
}

/*
--------------------------------------------------
void GLoadGameShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GLoadGameShow() {
	
	if(event_type == EVENT_RELEASE) return;
	
	if(is(LoadGame,SHOW)) {
		
		GLoadGameHide();
		
		return;
		
	}
	
	guiCurrentViewPreset = MENU_CAMERA_LOAD_GAME;
	
	
	
	GWorldNewHide();
	GOptionsHide();
	GTrophiesHide();
	GHelpHide();
	
	FillFromPool(files_list_LOADGAMESTR, files_list_LOADGAMESTR_Pool, 8, 0);
	
	set(LoadGame,SHOW);
	set(InputBox_LOADGAMESTR,SHOW);
	set(files_list_LOADGAMESTR,SHOW);
	
}

/*
--------------------------------------------------
void GLoadGameHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GLoadGameHide() {
	
	reset(LoadGame,SHOW);
	reset(files_list_LOADGAMESTR,SHOW);
	reset(InputBox_LOADGAMESTR,SHOW);
	
}

/*
--------------------------------------------------
void GTrophiesShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GTrophiesShow() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	guiCurrentViewPreset = MENU_CAMERA_TROPHIES;
	
	GHelpHide();
	GWorldNewHide();
	GLoadGameHide();
	GOptionsHide();
	
}

/*
--------------------------------------------------
void GTrophiesHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GTrophiesHide() {
	
	wait(1);
	
}

/*
--------------------------------------------------
void GHelpShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GHelpShow() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	guiCurrentViewPreset = MENU_CAMERA_HELP;
	
	GWorldNewHide();
	GLoadGameHide();
	GOptionsHide();
	GTrophiesHide();
	
}

/*
--------------------------------------------------
void GHelpHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GHelpHide() {
	
	wait(1);
	
}

/*
--------------------------------------------------
void FillFromPool(TEXT *dest, TEXT *pool, var amount, var scaler)

Desc:

Returns: -
--------------------------------------------------
*/
void FillFromPool(TEXT *dest, TEXT *pool, var amount, var scaler) {
	
	if(amount <= 0) return;
	
	while(!pool || !dest) wait(1);
	
	amount = abs(amount);
	
	int i = 0;
	while(i < amount) {
		
		str_cpy( (dest.pstring) [i], (pool.pstring) [ scaler*amount + i ] );
		
		i++;
		
	}
	
}

/*
--------------------------------------------------
void GPanelFade(PANEL *Panel, var start, var end, var speed)

Desc:

Returns: -
--------------------------------------------------
*/
void GPanelFade(PANEL *Panel, var start, var end, var speed) {
	
	while(!Panel) wait(1);
	if(start == end) return;
	
	speed = abs(speed);
	start = abs(start);
	end = abs(end);
	
	if(end>100) end=100;
	if(start>100) start=100;
	
	Panel->alpha = start;
	
	if(start > end) { // Fade out 
		
		while(Panel->alpha >= end) {
			
			Panel->alpha -= speed * time_step;
			wait(1);
			
		}
		
	}

	else { // Fade in

		while(Panel->alpha <= end) {
			
			Panel->alpha += speed * time_step;
			wait(1);
			
		}

	}

	Panel->alpha = end;

}

/*
--------------------------------------------------
void GNewGame_PreviewScene()

Desc:

Returns: -
--------------------------------------------------
*/
void GNewGame_PreviewScene() {
	
	
	
	GMainMenuHide();
	
}

/*
--------------------------------------------------
void GNewGame_UnPreviewScene()

Desc:

Returns: -
--------------------------------------------------
*/
void GNewGame_UnPreviewScene() {
	
	if(event_type == EVENT_CLICKUP) return;
	
	//	
	
	GMainMenuShow();
	
}

void GTEMPSTR_Up() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(TEMPSTR_Scaler > 0) {
		
		TEMPSTR_Scaler -= 1;
		
		FillFromPool(files_list_TEMPSTR, files_list_TEMPSTR_Pool, 20, TEMPSTR_Scaler );
		
	}
	
}

void GTEMPSTR_Down() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	TEMPSTR_Scaler += 1;
	FillFromPool(files_list_TEMPSTR, files_list_TEMPSTR_Pool, 20, TEMPSTR_Scaler );
	
}

/*
--------------------------------------------------
void GLOADGAMESTR_Up()

Desc:

Returns: -
--------------------------------------------------
*/
void GLOADGAMESTR_Up() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(LOADGAMESTR_Scaler > 0) {
		
		LOADGAMESTR_Scaler -= 1;
		FillFromPool(files_list_LOADGAMESTR, files_list_LOADGAMESTR_Pool, 8, LOADGAMESTR_Scaler);
	}
	
}

/*
--------------------------------------------------
void GLOADGAMESTR_Down()

Desc:

Returns: -
--------------------------------------------------
*/
void GLOADGAMESTR_Down() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	LOADGAMESTR_Scaler += 1;
	FillFromPool(files_list_LOADGAMESTR, files_list_LOADGAMESTR_Pool, 8, LOADGAMESTR_Scaler);
	
}

/*
--------------------------------------------------
void GSKYSTR_Up()

Desc:

Returns: -
--------------------------------------------------
*/
void GSKYSTR_Up() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(SKYSTR_Scaler > 0) {
		
		SKYSTR_Scaler -= 1;
		FillFromPool(files_list_SKYSTR, files_list_SKYSTR_Pool, 4, SKYSTR_Scaler);
		
	}
	
}

/*
--------------------------------------------------
void GSKYSTR_Down()

Desc:

Returns: -
--------------------------------------------------
*/
void GSKYSTR_Down() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	SKYSTR_Scaler += 1; // ++
	FillFromPool(files_list_SKYSTR, files_list_SKYSTR_Pool, 4, SKYSTR_Scaler);
	
}

/*
--------------------------------------------------
void GGROUNDSTR_Up()

Desc:

Returns: -
--------------------------------------------------
*/
void GGROUNDSTR_Up() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(GROUNDSTR_Scaler > 0) {
		
		GROUNDSTR_Scaler -= 1;
		FillFromPool(files_list_GROUNDSTR, files_list_GROUNDSTR_Pool, 4, GROUNDSTR_Scaler);
		
	}
	
}

/*
--------------------------------------------------
void GGROUNDSTR_Down()

Desc:

Returns: -
--------------------------------------------------
*/
void GGROUNDSTR_Down() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	GROUNDSTR_Scaler += 1;
	FillFromPool(files_list_GROUNDSTR, files_list_GROUNDSTR_Pool, 4, GROUNDSTR_Scaler);
	
}

/*
--------------------------------------------------
void GSwitchNewGameScreen ( var ID ) 

Desc:

Returns: -
--------------------------------------------------
*/
void GSwitchNewGameScreen ( var ID ) {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if( (int) ID == 1) {
		
		if(is(NewGame_Screen3,SHOW)) {
			
			if(WorldType == WORLD_DYNAMIC) { // Dynamic world was picked up before
				
				reset(NewGame_ScreenStatic_Step1,SHOW);
				set(NewGame_ScreenDyn_Step1,SHOW);
				
				if( !mystymoodActive ) LoadMystymood( true );
				
			}
			else { // Static world
				
				reset(NewGame_ScreenDyn_Step1,SHOW);  
				set(NewGame_ScreenStatic_Step1,SHOW);
				
				LoadMystymood( false );
				
			}
			
			reset(NewGame_Screen3,SHOW);
			set(NewGame_ScreenRight,SHOW);
			
			reset(InputBox_GROUNDSTR,SHOW);
			reset(InputBox_SKYSTR,SHOW);
			reset(files_list_GROUNDSTR,SHOW);
			reset(files_list_SKYSTR,SHOW);
			
			set(NewGame_PreviewButton,SHOW);
			
			return;
			
		}
		
		if(is(NewGame_ScreenDyn_Step1,SHOW) || is(NewGame_ScreenStatic_Step1,SHOW)) {
			
			reset(NewGame_ScreenDyn_Step1,SHOW);
			reset(NewGame_ScreenStatic_Step1,SHOW);
			reset(NewGame_PreviewButton,SHOW);
			
			set(NewGame_Screen1,SHOW);
			reset(NewGame_ScreenRight,SHOW);
			reset(NewGame_ScreenLeft,SHOW);
			
			LoadMystymood( false );
			
			GNewGameResetDynamicSettings();
			
			return;
			
			
		}
		
	}

	else {
		
		if(is(NewGame_Screen1,SHOW)) {
			
			if(WorldType == WORLD_DYNAMIC) { // Dynamic world was picked up before
				
				reset(NewGame_ScreenStatic_Step1,SHOW);
				set(NewGame_ScreenDyn_Step1,SHOW);
				
				if( !mystymoodActive ) LoadMystymood( true );
				
			}
			else { // Static world
			
				reset(NewGame_ScreenDyn_Step1,SHOW);  
				set(NewGame_ScreenStatic_Step1,SHOW);
				
				LoadMystymood( false );
				
			}
			
			reset(NewGame_Screen1,SHOW);
			
			set(NewGame_ScreenRight,SHOW);
			set(NewGame_ScreenLeft,SHOW);
			set(NewGame_PreviewButton,SHOW);
			
			return;
			
		}
		
		if(is(NewGame_ScreenDyn_Step1,SHOW) || is(NewGame_ScreenStatic_Step1,SHOW)) {
			
			reset(NewGame_ScreenDyn_Step1,SHOW);
			reset(NewGame_ScreenStatic_Step1,SHOW);
			reset(NewGame_PreviewButton,SHOW);
			
			set(NewGame_Screen3,SHOW);
			reset(NewGame_ScreenRight,SHOW);
			
			if( !mystymoodActive && WorldType == WORLD_DYNAMIC ) LoadMystymood( true );
			
			set(InputBox_GROUNDSTR,SHOW);
			set(InputBox_SKYSTR,SHOW);
			set(files_list_GROUNDSTR,SHOW);
			set(files_list_SKYSTR,SHOW);
			
			FillFromPool(files_list_GROUNDSTR, files_list_GROUNDSTR_Pool, 4, 0);					
			FillFromPool(files_list_SKYSTR, files_list_SKYSTR_Pool, 4, 0);
			
			return;
			
		}
		
	}
	
}

/*
--------------------------------------------------
void GNewGame_ChooseWorld(var ID)

Desc:

Returns: -
--------------------------------------------------
*/
void GNewGame_ChooseWorld(var ID) {
	
	if(event_type == EVENT_RELEASE) return;
	
	WorldType = (int) ID;
	
	//	
	
	GSwitchNewGameScreen(2);
	
}

/*
--------------------------------------------------
void GToggleMusicPlayerRandomize()

Desc:

Returns: -
--------------------------------------------------
*/
void GToggleMusicPlayerRandomize() {
	
	if(event_type == EVENT_RELEASE) return;
	
	
	
	if(button_state(MusicPlayer,5,-1)) mpRandomize = 1;
	else mpRandomize = 0;
	
}

/*
--------------------------------------------------
void GBlackboardAlphaFade()

Desc:

Returns: -
--------------------------------------------------
*/
void GBlackboardAlphaFade() {
	
	BBTranslucency = Blackboard->alpha;
	Blackboard->alpha = 20;
	
}

/*
--------------------------------------------------
void GBlackboardAlphaRestore()

Desc:

Returns: -
--------------------------------------------------
*/
void GBlackboardAlphaRestore() {
	
	if(BBTranslucency) Blackboard->alpha = BBTranslucency;
	
}

/*
--------------------------------------------------
void GToggleStatistics()

Desc:

Returns: -
--------------------------------------------------
*/
void GToggleStatistics() {
	
	if(event_type == EVENT_RELEASE) return;

	if( is(StatsPanel,SHOW) )   {
		
		reset(StatsPanel,SHOW);
		reset(Stats,SHOW);
		
		return;
		
	}
	
	StatsPanel->pos_x = 50;
	StatsPanel->pos_y = 50;
	
	
	
	set(StatsPanel,SHOW);
	set(Stats,SHOW);
	
	while( is(StatsPanel,SHOW) ) {
		
		ConvertToCTFormat((StatsPanel.pstring) [0], CountObjects, MAX_OBJECTS);
		ConvertToCTFormat((StatsPanel.pstring) [1], CountParticles, MAX_PARTICLES);
		ConvertToCTFormat((StatsPanel.pstring) [2], CountLights, MAX_LIGHTS);
		ConvertToCTFormat((StatsPanel.pstring) [3], CountSounds, MAX_SOUNDS );
		ConvertToCTFormat((StatsPanel.pstring) [4], CountSprites, MAX_SPRITES);
		ConvertToCTFormat((StatsPanel.pstring) [5], CountObjects+CountParticles+CountLights+CountSounds+CountSprites, MAX_TOTAL);
		
		StatsPanel->pos_x = Stats->pos_x + 266;
		StatsPanel->pos_y = Stats->pos_y + 66;
		
		wait(1);
		
	}
}

/*
--------------------------------------------------
void GInDevHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GInDevHide() {
	
	if(event_type == EVENT_RELEASE) return;
	
	reset(InDev,SHOW);
	
}

/*
--------------------------------------------------
void GInDevShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GInDevShow() {
	
	if(event_type == EVENT_RELEASE) return;
	
	set(InDev,SHOW);
	
}

/*
--------------------------------------------------
void GBackMenuShow()

Desc:

Returns: -
--------------------------------------------------
*/
void GBackMenuShow() {
	
	if(event_type == EVENT_RELEASE) return;
	
	GGUIHide();	
	set(BackMenu_Background,SHOW);
	set(BackMenu_Items,SHOW);
	
}

/*
--------------------------------------------------
void GBackMenuHide()

Desc:

Returns: -
--------------------------------------------------
*/
void GBackMenuHide() {
	
	if(event_type == EVENT_RELEASE) return;
	
	reset(BackMenu_Background,SHOW);
	reset(BackMenu_Items,SHOW);
	
	GGUIShow();
	
}

/*
--------------------------------------------------
void GPanelMoveAlpha(PANEL *p, var mode, var oldpos, var newpos, var oldAlpha, var newAlpha, var speed)

Desc:

Returns: -
--------------------------------------------------
*/
void GPanelMoveAlpha(PANEL *p, var mode, var oldpos, var newpos, var oldAlpha, var newAlpha, var speed) {
	
	while(!p) wait(1);
	
	speed = abs(speed);
	if( speed <= 0) speed = 5;
	
	int OldFlag = is(p,TRANSLUCENT), OldAlpha = p->alpha;		
	if(oldpos > newpos) {
		
		var swapped = oldpos + newpos;
		oldpos = swapped - oldpos;
		newpos = swapped - newpos;
		
	}

	set(p,TRANSLUCENT);

	if(mode == X) { // Move along the x-axis

		p.pos_x = oldpos;

		while(p.pos_x <= newpos) {
			
			p.pos_x += speed * time_step;
			p.alpha = GetPercent(p.pos_x, newpos);
			
			wait(1);
		}

		p.pos_x = newpos;
		
	}
	
	else { // y-axis
		
		p.pos_y = oldpos;

		while(p.pos_y <= newpos) {
			
			p.pos_y += speed * time_step;
			p.alpha = GetPercent(p.pos_y, newpos);
			
			wait(1);
		}

		p.pos_y = newpos;
		
		
	}
	
	p.alpha = GetPercent(1,1); // = 100%
	
	if( !OldFlag ) {
		
		p->alpha = OldAlpha;
		reset(p,TRANSLUCENT);
		
	}
	
}

/*
--------------------------------------------------
void GPanelMoveAlphaX(PANEL *Panel, var oldx, var newx, var speed)

Desc:

Returns: -
--------------------------------------------------
*/
void GPanelMoveAlphaX(PANEL *Panel, var oldx, var newx, var speed) {
	
	GPanelMoveAlpha(Panel,X,oldx,newx,0,0,speed);   
	
}

/*
--------------------------------------------------
void GPanelMoveAlphaY(PANEL *Panel, var oldy, var newy, var speed)

Desc: 

Returns: -
--------------------------------------------------
*/
void GPanelMoveAlphaY(PANEL *Panel, var oldy, var newy, var speed) {
	
	GPanelMoveAlpha(Panel,Y,oldy,newy,0,0,speed);
	
}

void KillInGameMusic () {
	
	var _midi_vol = midi_vol;
	while( midi_vol > 0 ) { midi_vol -= 5 * time_step; wait ( 1 ) ;  } midi_vol = _midi_vol;
	
	media_stop(mpHandle);
	
}

void GQuitToMainMenu() {
	
	if(event_type == EVENT_RELEASE) return;
	
	mouse_mode = 0;
	
	// old code from kernel
	CreateWorld->alpha = 0;
	set(CreateWorld,SHOW);
	while(CreateWorld->alpha <= 100) {
		
		CreateWorld->alpha += 5 * time_step;
		wait(1);
		
	}
	set(CreateWorldCoffee,SHOW);
	
	KillInGameMusic ();
	
	GBackMenuHide();
	GGUIHide();
	
	GLoadMainMenu();
	while(proc_status(GLoadMainMenu)) wait(1);
	
	// Release resources
	if( TerrainEnt ) ptr_remove ( TerrainEnt );
	if( marker ) ptr_remove ( marker );
	if( select ) ptr_remove ( select );
	
	mouse_mode = 4;
	
	reset(CreateWorldCoffee,SHOW);
	
	while(CreateWorld->alpha > 0) {
		
		CreateWorld->alpha -= 5 * time_step;
		wait(1);
		
	}	
	reset(CreateWorld,SHOW);
	
}


/*
--------------------------------------------------
int PassObjectPropertiesToGUI(ENTITY *e)

Desc: Passes object's properties to the GUI.

Returns: -1 if the appropriate GUI panel haven't
yet been opened.
--------------------------------------------------
*/
int PassObjectPropertiesToGUI(ENTITY *e) {

	WriteLog("[ ] Trying to pass object information to the appropriate panel...");
	NewLine();

	if(!is(panProp,SHOW)) return -1; // Not necessary to use WriteLog here.

	v_objectz = 3000 - e.z;
	v_ambient = e.ambient;
	v_alpha = 100 - e.alpha;

	if(is(e,BRIGHT)) button_state(panProp,2,1);
	else button_state(panProp,2,0);

	if(is(e,INVISIBLE)) button_state(panProp,3,1);
	else button_state(panProp,3,0);

	if(is(e,NOFOG)) button_state(panProp,4,1);
	else button_state(panProp,4,0);

	if(is(e,OVERLAY)) button_state(panProp,5,1);
	else button_state(panProp,5,0);

	if(is(e,PASSABLE)) button_state(panProp,6,1);
	else button_state(panProp,6,0);

	if(is(e,POLYGON)) button_state(panProp,7,1);
	else button_state(panProp,7,0);

	if(is(e,SHADOW)) button_state(panProp,8,1);
	else button_state(panProp,8,0);

	if(is(e,TRANSLUCENT)) button_state(panProp,9,1);
	else button_state(panProp,9,0);
	
	WriteLog("[X] Task completed.");
	NewLine();

}

/*
--------------------------------------------------
void guiViewPreset (int* ref, int id, VECTOR* _pos, VECTOR* _ang)

Desc:

Returns: -
--------------------------------------------------
*/
void guiViewPreset (int* ref, int id, VECTOR* _pos, VECTOR* _ang)
{
	VECTOR pos, ang;
	vec_set(&pos, _pos);
	vec_set(&ang, _ang);

	while ( ! cbInBuildment )
	{  
		if (*ref == id)
		{
			vec_lerp(camera.x, camera.x, pos.x, clamp(guiViewPresetSpeed * time_step, 0, 1));
			vec_lerp(camera.pan, camera.pan, ang.x, clamp(guiViewPresetSpeed * time_step, 0, 1));
		} 
		
		wait(1);
	}
}

void SECreate_PlayerNormal () { if(event_type == EVENT_RELEASE ) return; SystemObjectID = Trigger_PlayerStandard; GInsertObjectHide(); }
void SECreate_PlayerBike () { if(event_type == EVENT_RELEASE ) return; SystemObjectID = Trigger_PlayerBike; GInsertObjectHide(); }
void SECreate_SpawnNotification() { if (event_type == EVENT_RELEASE ) return; SystemObjectID = Trigger_SpawnNotification; GInsertObjectHide(); }

#endif