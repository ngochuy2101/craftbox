PANEL *buttonlst;

TEXT *t_panProp[3];

/*
BMAP *button_New = "button_general.bmp";
BMAP *button_New_Over = "button_general_over.bmp";

BMAP *button_Open = "button_general.bmp";
BMAP *button_Open_Over = "button_general_over.bmp";

BMAP *button_Save = "button_general.bmp";
BMAP *button_Save_Over = "button_general_over.bmp";
*/

BMAP *button_black = "button_black.bmp";

BMAP *button_Copy = "button_general.bmp";
BMAP *button_Copy_Over = "button_general_over.bmp";

BMAP *button_Paste = "button_general.bmp";
BMAP *button_Paste_Over = "button_general_over.bmp";

BMAP *button_Delete = "button_general.bmp";
BMAP *button_Delete_Over = "button_general_over.bmp";

BMAP *button_Move = "button_general.bmp";
BMAP *button_Move_Over = "button_general_over.bmp";

BMAP *button_Rotate = "button_general.bmp";
BMAP *button_Rotate_Over = "button_general_over.bmp";

BMAP *button_Scale = "button_general.bmp";
BMAP *button_Scale_Over = "button_general_over.bmp";

BMAP *button_Prop = "button_general.bmp";
BMAP *button_Prop_Over = "button_general_over.bmp";

BMAP *button_Phy = "button_general.bmp";
BMAP *button_Phy_Over = "button_general_over.bmp";

BMAP *button_Mat = "button_general.bmp";
BMAP *button_Mat_Over = "button_general_over.bmp";

BMAP *button_Home = "button_general.bmp";
BMAP *button_Home_Over = "button_general_over.bmp";

BMAP *button_Cam = "button_general.bmp";
BMAP *button_Cam_Over = "button_general_over.bmp";

BMAP *button_Terrain = "button_general.bmp";
BMAP *button_Terrain_Over = "button_general_over.bmp";

BMAP *button_Objs = "button_general.bmp";
BMAP *button_Objs_Over = "button_general_over.bmp";

BMAP *button_Path = "button_general.bmp";
BMAP *button_Path_Over = "button_general_over.bmp";

BMAP *button_Close = "button_Close.bmp";

BMAP *button_Home_newworld = "button_Home_newworld.bmp";
BMAP *button_Home_loadworld = "button_Home_loadworld.bmp";
BMAP *button_Home_saveworld = "button_Home_saveworld.bmp";
BMAP *button_Home_compileworld = "button_Home_compileworld.bmp";
BMAP *button_Home_configworld = "button_Home_configworld.bmp";
BMAP *button_Home_quitworld = "button_Home_quitworld.bmp";

BMAP *flag_BIRGHT_EDITOR = "flag_BIRGHT_EDITOR.bmp";
BMAP *flag_BIRGHT_EDITOR_on = "flag_BIRGHT_EDITOR_on.bmp";

BMAP *flag_INVISIBLE_EDITOR = "flag_INVISIBLE_EDITOR.bmp";
BMAP *flag_INVISIBLE_EDITOR_on = "flag_INVISIBLE_EDITOR_on.bmp";

BMAP *flag_NOFOG_EDITOR = "flag_NOFOG_EDITOR.bmp";
BMAP *flag_NOFOG_EDITOR_on = "flag_NOFOG_EDITOR_on.bmp";

BMAP *flag_OVERLAY_EDITOR = "flag_OVERLAY_EDITOR.bmp";
BMAP *flag_OVERLAY_EDITOR_on = "flag_OVERLAY_EDITOR_on.bmp";

BMAP *flag_PASSABLE_EDITOR = "flag_PASSABLE_EDITOR.bmp";
BMAP *flag_PASSABLE_EDITOR_on = "flag_PASSABLE_EDITOR_on.bmp";

BMAP *flag_POLYGON_EDITOR = "flag_POLYGON_EDITOR.bmp";
BMAP *flag_POLYGON_EDITOR_on = "flag_POLYGON_on.bmp";

BMAP *flag_SHADOW_EDITOR = "flag_SHADOW_EDITOR.bmp";
BMAP *flag_SHADOW_EDITOR_on = "flag_SHADOW_EDITOR_on.bmp";

BMAP *flag_TRANSLUCENT_EDITOR = "flag_TRANSLUCENT_EDITOR.bmp";
BMAP *flag_TRANSLUCENT_EDITOR_on = "flag_TRANSLUCENT_EDITOR_on.bmp";

BMAP *slider = "xlider.bmp";

var 
/* buttons which is used for the main HUD. */
button_New_x,
button_Open_x,
button_Save_x,
button_Copy_x,
button_Paste_x,
button_Delete_x,
button_Move_x,
button_Rotate_x,
button_Scale_x,
button_Prop_x,
button_Phy_x,
button_Mat_x,
button_Home_x,			button_Home_y,
button_Cam_x,			button_Cam_y,
button_Terrain_x,		button_Terrain_y,
button_Objs_x,			button_Objs_y,
button_Path_x,			button_Path_y,

button_SaveWorld_y,
button_LoadWorld_y,
button_NewWorld_y,
button_QuitWorld_y,
button_CmpWorld_y,
button_SetWorld_y;


PANEL *panHome = {
	layer = 2;
	
	bmap = "panHome_EDITOR.bmp";
	
	button(0,0,button_Home_saveworld,button_Home_saveworld,button_Home_saveworld,NULL,NULL,NULL);
	button(0,0,button_Home_loadworld,button_Home_loadworld,button_Home_loadworld,NULL,NULL,NULL);
	button(0,0,button_Home_newworld,button_Home_newworld,button_Home_newworld,NULL,NULL,NULL);
	button(0,0,button_Home_quitworld,button_Home_quitworld,button_Home_quitworld,NULL,NULL,NULL);
	button(0,0,button_Home_compileworld,button_Home_compileworld,button_Home_compileworld,NULL,NULL,NULL);
	button(0,0,button_Home_configworld,button_Home_configworld,button_Home_configworld,NULL,NULL,NULL);
	
	button(0,0,button_Close,button_Close,button_Close,sharedGUI_closewindow,NULL,NULL);
	
	on_click = sharedGUI_dragpanel;
	
	flags = OVERLAY | TRANSLUCENT;
}

PANEL *panProp = {
	layer = 2;
	
	bmap = "panProp_EDITOR.bmp";
	
	button_toggle(0,0,flag_BIRGHT_EDITOR_on,flag_BIRGHT_EDITOR,flag_BIRGHT_EDITOR_on,flag_BIRGHT_EDITOR_on,NULL,NULL,NULL);
	button_toggle(0,0,flag_INVISIBLE_EDITOR_on,flag_INVISIBLE_EDITOR,flag_INVISIBLE_EDITOR_on,flag_INVISIBLE_EDITOR_on,NULL,NULL,NULL);
	button_toggle(0,0,flag_NOFOG_EDITOR_on,flag_NOFOG_EDITOR,flag_NOFOG_EDITOR_on,flag_NOFOG_EDITOR_on,NULL,NULL,NULL);
	button_toggle(0,0,flag_OVERLAY_EDITOR_on,flag_OVERLAY_EDITOR,flag_OVERLAY_EDITOR_on,flag_OVERLAY_EDITOR_on,NULL,NULL,NULL);
	button_toggle(0,0,flag_PASSABLE_EDITOR_on,flag_PASSABLE_EDITOR,flag_PASSABLE_EDITOR_on,flag_PASSABLE_EDITOR_on,NULL,NULL,NULL);
	button_toggle(0,0,flag_POLYGON_EDITOR_on,flag_POLYGON_EDITOR,flag_POLYGON_EDITOR_on,flag_POLYGON_EDITOR_on,NULL,NULL,NULL);
	button_toggle(0,0,flag_SHADOW_EDITOR_on,flag_SHADOW_EDITOR,flag_SHADOW_EDITOR_on,flag_SHADOW_EDITOR_on,NULL,NULL,NULL);
	button_toggle(0,0,flag_TRANSLUCENT_EDITOR_on,flag_TRANSLUCENT_EDITOR,flag_TRANSLUCENT_EDITOR_on,flag_TRANSLUCENT_EDITOR_on,sharedGUI_toggle_translucent,NULL,NULL);
	
	hslider(0,0,100,slider,0,100,fpsf_alpha_control);	
	hslider(0,0,100,slider,0,100,fpsf_ambient_control);	
	hslider(0,0,100,slider,0,100,fpsf_albedo_control);	
	
	button(0,0,button_Close,button_Close,button_Close,sharedGUI_closewindow,NULL,NULL);
	
	on_click = sharedGUI_dragpanel;
	
	flags = TRANSLUCENT | OVERLAY;
}

PANEL *panPhy = {
	layer = 2;
	
	bmap = "panPhy_EDITOR.bmp";
	
	button(0,0,button_Close,button_Close,button_Close,sharedGUI_closewindow,NULL,NULL);
	
	on_click = sharedGUI_dragpanel;
	
	flags = OVERLAY | TRANSLUCENT;
}

PANEL *panMat = {
	layer = 2;
	
	bmap = "panMat_EDITOR.bmp";
	
	button(0,0,button_Close,button_Close,button_Close,sharedGUI_closewindow,NULL,NULL);
	
	on_click = sharedGUI_dragpanel;
	
	flags = OVERLAY | TRANSLUCENT;
}

void sharedGUI_updategui(PANEL *wg) {
	
	if(wg == panHome) {
		button_SaveWorld_y = BORDER;
		button_LoadWorld_y = button_SaveWorld_y + 40 + BORDER/2.5;
		button_NewWorld_y = button_LoadWorld_y + 40 + BORDER/2.5;
		button_QuitWorld_y = button_NewWorld_y + 40 + BORDER/2.5;
		button_CmpWorld_y = button_QuitWorld_y + 40 + BORDER/2.5;
		button_SetWorld_y = button_CmpWorld_y + 40 + BORDER/2.5;
		
		pan_setpos(panHome,3,1,vector(BORDER,button_SaveWorld_y,0));
		pan_setpos(panHome,3,2,vector(BORDER,button_LoadWorld_y,0));	
		pan_setpos(panHome,3,3,vector(BORDER,button_NewWorld_y,0));
		pan_setpos(panHome,3,4,vector(BORDER,button_QuitWorld_y,0));
		pan_setpos(panHome,3,5,vector(BORDER,button_CmpWorld_y,0));
		pan_setpos(panHome,3,6,vector(BORDER,button_SetWorld_y,0));
		
		pan_setpos(panHome,3,7,vector(bmap_width(panHome.bmap) - BORDER * 2,BORDER,0));
		
	}
	
	if(wg == panProp) { 
		
		int i;
		for(i = 0;i < 3;i++) t_panProp[i].pos_x = panProp.pos_x + 102 + (2 * BORDER);
		
		t_panProp[0].pos_y = (panProp.pos_y + (5 * BORDER)) - 15;
		t_panProp[1].pos_y = (panProp.pos_y + (10 * BORDER)) - 15;
		t_panProp[2].pos_y = (panProp.pos_y + (15 * BORDER)) - 15;
		
		int i;
		for(i = 1;i < 9;i++)
		pan_setpos(panProp,3,i,vector(BORDER,BORDER + 23 * i,0));
		
		pan_setpos(panProp,4,1,vector(BORDER + 102,BORDER * 2 + 23,0));
		pan_setpos(panProp,4,2,vector(BORDER + 102,BORDER * 3 + 23 * 2,0));
		pan_setpos(panProp,4,3,vector(BORDER + 102,BORDER * 4 + 23 * 3,0));
		
	}
	
	if(wg == panMat) {
		wait(1);
	}
	
	if(wg == panPhy) {
		wait(1);
	}
}

/* 

id always = 1 cuz we don't have two closebuttons at the same time. 
only one PANEL * parameter isn't enough (and it won't work too) so 
this simple ugly hack should do the trick.

*/
void sharedGUI_closewindow(var id, PANEL *p) {
	id = 1;
	
	/*
	select.alpha = fpsf_alpha_control;
	select.ambient = fpsf_ambient_control;
	select.albedo = fpsf_albedo_control;
	
	printf("%d,%d,$d",select.alpha,select.ambient,select.albedo);
	*/
	
	if(p == panHome) {
		reset(panHome,SHOW);

		enable_click = 1;
		wait(1);
	}
	
	if(p == panPhy) {
		reset(panPhy,SHOW);
		
		enable_click  = 1;
	}
	
	if(p == panMat) {
		reset(panMat,SHOW);
		
		enable_click = 1;
	}
	
	if(p == panProp) {		
		int i;
		for(i = 0;i < 3;i++) txt_remove(t_panProp[i]);
		
		reset(panProp,SHOW);
	}
}

void sharedGUI_dragpanel(PANEL *p)
{
	var click_offset[2];
	
	click_offset[0]=p.pos_x - mouse_pos.x;
	click_offset[1]=p.pos_y - mouse_pos.y;
	
	sharedGUI_panelselect(p);
	
	while(mouse_left)
	{
		proc_mode = PROC_EARLY;
		
		is_select = 1;
		
		p.pos_x = mouse_pos.x+click_offset[0];
		p.pos_y = mouse_pos.y+click_offset[1];
		
		//hack hack hack!!!!
		if(p == panHome) sharedGUI_updategui(panHome);
		if(p == panProp) sharedGUI_updategui(panProp);
		if(p == panPhy) sharedGUI_updategui(panPhy);
		if(p == panMat) sharedGUI_updategui(panMat);
		
		//		sharedGUI_panelselect(p);
		wait(1);
	}
	
	//hack to prevent shit happens. f.e. after dragged the guis' elements didn't retain their original location.
	if(p == panHome) sharedGUI_updategui(panHome);
	if(p == panProp) sharedGUI_updategui(panProp);
	if(p == panPhy) sharedGUI_updategui(panPhy);
	if(p == panMat) sharedGUI_updategui(panMat);
	
	is_select = 0;
}

void sharedGUI_centerpanel(PANEL *p) {
	while(p == NULL) wait(1);
	
	p.pos_x = (screen_size.x - bmap_width(p.bmap)) / 2; 
	p.pos_y = (screen_size.y - bmap_height(p.bmap)) / 2;
}

void sharedGUI_loadbuttons() {
	buttonlst.size_x = screen_size.x;
	buttonlst.size_y = screen_size.y;
	
	// Initialize variables use for positioning elements in the panel (X first)
	// Top-left ( left-to-right )
	button_New_x = BORDER;
	button_Open_x = BORDER + SPACE;
	button_Save_x = button_Open_x + SPACE;
	
	// Top-right, ( right-to-left )
	button_Mat_x = screen_size.x - BORDER - (BUTTON_SIZE * 3);
	button_Phy_x = button_Mat_x - (SPACE);
	button_Prop_x = button_Phy_x - (SPACE);
	
	button_Scale_x = button_Prop_x - ((SPACE) * 1.25);
	button_Rotate_x = button_Scale_x - (SPACE);
	button_Move_x = button_Rotate_x - (SPACE);
	
	button_Delete_x = button_Move_x - ((SPACE) * 1.25);
	button_Paste_x = button_Delete_x - (SPACE);
	button_Copy_x = button_Paste_x - (SPACE);
	
	// Down-left ( left-to-right )
	button_Home_x = button_New_x;
	button_Cam_x = button_Open_x;
	button_Terrain_x = button_Save_x;
	button_Objs_x = button_Terrain_x + SPACE;
	button_Path_x = button_Objs_x + SPACE;
	
	// Initialize variables use for positioning elements in the panel (Y)
	// For down-left
	button_Home_y = screen_size.y - BORDER - BUTTON_SIZE;
	
	pan_setpos(buttonlst,3,1,vector(button_New_x,BORDER,0));
	pan_setpos(buttonlst,3,2,vector(button_Open_x,BORDER,0));
	pan_setpos(buttonlst,3,3,vector(button_Save_x,BORDER,0));
	
	pan_setpos(buttonlst,3,12,vector(button_Mat_x,BORDER,0));
	pan_setpos(buttonlst,3,11,vector(button_Phy_x,BORDER,0));
	pan_setpos(buttonlst,3,10,vector(button_Prop_x,BORDER,0));\
	
	pan_setpos(buttonlst,3,9,vector(button_Scale_x,BORDER,0));
	pan_setpos(buttonlst,3,8,vector(button_Rotate_x,BORDER,0));
	pan_setpos(buttonlst,3,7,vector(button_Move_x,BORDER,0));
	
	pan_setpos(buttonlst,3,6,vector(button_Delete_x,BORDER,0));
	pan_setpos(buttonlst,3,5,vector(button_Paste_x,BORDER,0));
	pan_setpos(buttonlst,3,4,vector(button_Copy_x,BORDER,0));
	
	pan_setpos(buttonlst,3,17,vector(button_Home_x,button_Home_y,0));
	pan_setpos(buttonlst,3,16,vector(button_Cam_x,button_Home_y,0));
	pan_setpos(buttonlst,3,15,vector(button_Terrain_x,button_Home_y,0));
	pan_setpos(buttonlst,3,14,vector(button_Objs_x,button_Home_y,0));
	pan_setpos(buttonlst,3,13,vector(button_Path_x,button_Home_y,0));
}

void sharedGUI__loadbuttons() {
	if(is(buttonlst,SHOW)) reset(buttonlst,SHOW);
}

PANEL *buttonlst = {
	size_x = 800;
	size_y = 600;
	layer = 1;
	
	/*
	button(0,0,button_New,button_New,button_New_Over,NULL,NULL,NULL);
	button(0,0,button_Open,button_Open,button_Open_Over,NULL,NULL,NULL);
	button(0,0,button_Save,button_Save,button_Save_Over,NULL,NULL,NULL);
	*/
	
	button(0,0,button_black,button_black,button_black,NULL,NULL,NULL);
	button(0,0,button_black,button_black,button_black,NULL,NULL,NULL);
	button(0,0,button_black,button_black,button_black,NULL,NULL,NULL);
	
	button(0,0,button_Copy,button_Copy,button_Copy_Over,NULL,NULL,NULL);
	button(0,0,button_Paste,button_Paste,button_Paste_Over,NULL,NULL,NULL);
	button(0,0,button_Delete,button_Delete,button_Delete_Over,NULL,NULL,NULL);
	
	button(0,0,button_Move,button_Move,button_Move_Over,NULL,NULL,NULL);
	button(0,0,button_Rotate,button_Rotate,button_Rotate_Over,NULL,NULL,NULL);
	button(0,0,button_Scale,button_Scale,button_Scale_Over,NULL,NULL,NULL);
	
	button(0,0,button_Prop,button_Prop,button_Prop_Over,sharedGUI_prop,NULL,NULL);
	button(0,0,button_Phy,button_Phy,button_Phy_Over,sharedGUI_phy,NULL,NULL);
	button(0,0,button_Mat,button_Mat,button_Mat_Over,sharedGUI_mat,NULL,NULL);
	
	button(0,0,button_Path,button_Path,button_Path_Over,NULL,NULL,NULL);
	button(0,0,button_Objs,button_Objs,button_Objs_Over,NULL,NULL,NULL);
	button(0,0,button_Terrain,button_Terrain,button_Terrain_Over,NULL,NULL,NULL);
	button(0,0,button_Cam,button_Cam,button_Cam_Over,NULL,NULL,NULL);
	button(0,0,button_Home,button_Home,button_Home_Over,sharedGUI_home,NULL,NULL);
	
	flags = OVERLAY | SHOW;
}

//panel_set
STRING *sharedGUI_releaseStr = "                       ";

TEXT *sharedGUI_releaseTEXT = {
	string(sharedGUI_releaseStr);
	font = "Arial#25b";
}

PANEL *_logo = {
	bmap = "_logo.bmp";
	flags = OVERLAY;	
}

PANEL *blackscreen = {
	bmap = "bitmap.bmp";
}

PANEL *blackpix = {
	bmap = "black.bmp";
}

void sharedGUI_loadscene(STRING *s) {
	level_load(s);
}

void sharedGUI_rescale(PANEL *p) {
	while(p == NULL) wait(1);
	
	p.pos_x = 0;
	p.pos_y = 0;
	
	p.scale_x = screen_size.x/bmap_width(p.bmap);
	p.scale_y = screen_size.y/bmap_height(p.bmap);
}

void sharedGUI_blackscreen(int mode, int sec) {
	sharedGUI_rescale(blackscreen);
	set(blackscreen,SHOW);
	
	if(mode == FADE_IN) {
		set(blackscreen,TRANSLUCENT);
		blackscreen->alpha = 0;
		
		wait(-sec);
		
		while(blackscreen->alpha <= 100) {
			blackscreen->alpha += 10 * time_step;
			wait(1);
		}
		
		blackscreen->alpha = 100;
		
	}
	
	if(mode == FADE_OUT) {
		if(!is(blackscreen,SHOW)) set(blackscreen,SHOW);
		set(blackscreen,TRANSLUCENT);
		blackscreen->alpha = 100;
		
		wait(-sec);
		
		while(blackscreen->alpha >= 0) {
			blackscreen->alpha -= 10 * time_step;
			wait(1);
		}
		
		blackscreen->alpha = 0;
		reset(blackscreen,SHOW);
		
	}
}

void sharedGUI_loadlogo() {
	// Initial setup	
	_logo->size_x = bmap_width(_logo.bmap);
	_logo->size_y = bmap_height(_logo.bmap);
	
	_logo->pos_x = screen_size.x - bmap_width(_logo.bmap) - 25;
	_logo->pos_y = 25;
	
	set(_logo,SHOW);
}

void sharedGUI__loadlogo() {
	if(is(_logo,SHOW)) reset(_logo,SHOW);
}

void sharedGUI_release() {
	
	str_cpy(sharedGUI_releaseStr,"Editor");

	sharedGUI_releaseTEXT->pos_x = screen_size.x - str_width(sharedGUI_releaseStr,"Arial#25b");
	sharedGUI_releaseTEXT->pos_y = screen_size.y - str_width(sharedGUI_releaseStr,"Arial#25b");
	
	set(sharedGUI_releaseTEXT,SHOW);
}

void sharedGUI__release() {
	if(is(sharedGUI_releaseTEXT,SHOW)) reset(sharedGUI_releaseTEXT,SHOW);
	str_cpy(sharedGUI_releaseStr,"");
}

void sharedGUI_playintro(int vol) {
	proc_kill(4);
	
	var hndl;
	hndl = media_play("",NULL,100);

	while(media_playing(hndl)) wait(1);
}

int instance;
PANEL *inst = {
	layer=25;
	digits(0,0,99,"Arial#25b",1,instance);
	flags=SHOW;
}

void sharedGUI_loadbackground() {
	//		sharedGUI_playintro(100);
	//		wait_for(sharedGUI_playintro);
	
	sharedGUI_loadscene("small.hmp");
	wait_for(sharedGUI_loadscene);
	
	sharedGUI_loadbuttons();
	wait_for(sharedGUI_loadbuttons);
	
	sharedGUI_blackscreen(FADE_OUT,2);
	wait_for(sharedGUI_blackscreen);
	
	sharedGUI_mouse(ON);
}

void sharedGUI_mouse(int mode) {
	if(mode == OFF) mouse_mode = 0;
	if(mode == ON) mouse_mode = 4;
}

void sharedGUI_mouseset(BMAP *b) {
	mouse_map = b;
}

void sharedGUI_home() {
	enable_click = 0;
	
	sharedGUI_centerpanel(panHome);
	sharedGUI_updategui(panHome);
	
	set(panHome,SHOW);
}

void sharedGUI_prop() {
	enable_click = 0;
	
	int i;
	for(i = 0;i < 3;i++) {
		t_panProp[i] = txt_create(1,3);
		t_panProp[i].font = f;
	}
	
	str_cpy((t_panProp[0].pstring)[0],"Alpha");
	str_cpy((t_panProp[1].pstring)[0],"Ambient");
	str_cpy((t_panProp[2].pstring)[0],"Albedo");
	
	panProp.pos_x = BORDER;
	panProp.pos_y = screen_size.y - (2 * BORDER) - 32 - bmap_height(panProp.bmap);
	
	sharedGUI_updategui(panProp);
	
	set(panProp,SHOW);
	
	int i; for(i = 0;i < 3;i++) set(t_panProp[i],SHOW);
}

void sharedGUI_mat() {
	enable_click = 0;
	
	sharedGUI_centerpanel(panMat);
	sharedGUI_updategui(panMat);
	
	set(panMat,SHOW);
}

void sharedGUI_phy() {
	enable_click = 0;
	
	sharedGUI_centerpanel(panPhy);
	sharedGUI_updategui(panPhy);
	
	set(panPhy,SHOW);
}

void sharedGUI_toggle_translucent() {
	wait(1);
}

PANEL *debug = {
	layer=6;
	digits(0,0,99,"arial#25b",1,fpsf_alpha_control);
	digits(0,20,99,"arial#25b",1,fpsf_albedo_control);
	digits(0,40,99,"arial#25b",1,fpsf_ambient_control);
	digits(0,60,99,"arial#25b",1,enable_click);
	
	flags=SHOW;
}

void sharedGUI_panelselect(PANEL *p)
{
	if(last_pan) {
		last_pan.alpha = DEFAULT_ALPHA;
		layer_sort(last_pan,2);
		
		last_pan = p;
		layer_sort(last_pan,3);
		last_pan.alpha = 100;
	}
	else {
		last_pan = p;
		layer_sort(last_pan,3);
		last_pan.alpha = 100;
	}
}

void init_startup() {
	panHome.alpha = panMat.alpha = panPhy.alpha = panProp.alpha = DEFAULT_ALPHA;
}