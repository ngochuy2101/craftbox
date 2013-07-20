
/////////////////////////////////////////////////////////////////////
// Default key and debug functions
// (c) jcl / Conitec  2008
// Custom default.c <A8.h>, 25.6.2013, Nguyen Ngoc Huy (d3dx9_30.dll/Scifi)
// 5.7.2013
/////////////////////////////////////////////////////////////////////

#ifndef default_c
	#define default_c
	#include <acknex.h> // standard engine objects

	var def_dfps,def_dtps,def_dtlv,def_dtcs,def_dtac,def_dtrf,def_dsnd;
	ANGLE def_cang;
	
	BOOL engine_play = 0;
	
	VIEW* viewMap = 
	{
		flags = WIREFRAME | NOCULL; 
		layer = 1; 
		roll = 270; 
		tilt = -90; 
		arc = 10; 
	}

	PANEL* def_debug_pan = 
	{
		pos_x = 5; 
		pos_y = 5; 
		layer = 998;

		digits(0,2,"%4.0fx","Arial#14b",1,screen_size.x);
		digits(30,2,"%.0f","Arial#14b",1,screen_size.y);
		digits(0,12,"fps%5.0f","Arial#14b",16,def_dfps);
		digits(0,22,"pps%5.0fk","Arial#14b",0.016,def_dtps);
		digits(0,32,"x%7.0f","Arial#14b",1,camera.x);
		digits(0,42,"y%7.0f","Arial#14b",1,camera.y);
		digits(0,52,"z%7.0f","Arial#14b",1,camera.z);
		digits(0,62,"pan%5.0f","Arial#14b",1,def_cang.pan);
		digits(0,72,"til%5.0f","Arial#14b",1,def_cang.tilt);
		digits(0,82,"rol%5.0f","Arial#14b",1,def_cang.roll);

		digits(65,2,"ms/frame","Arial#14b",0,0);
		digits(65,12,"geo%5.1f","Arial#14b",1,def_dtlv);
		digits(65,22,"ent%5.1f","Arial#14b",1,time_entities);
		digits(65,32,"par%5.1f","Arial#14b",1,time_effects);
		digits(65,42,"drw%5.1f","Arial#14b",1,time_draw);
		digits(65,52,"pan%5.1f","Arial#14b",1,time_panels);
		digits(65,62,"ref%5.1f","Arial#14b",1,def_dtrf);
		digits(65,72,"srv%5.1f","Arial#14b",1,def_dtcs);
		digits(65,82,"fnc%5.1f","Arial#14b",1,def_dtac);

		digits(130,2,"count of","Arial#14b",0,0);
		digits(130,12,"ent%5.0f","Arial#14b",1,num_entities);
		digits(130,22,"vis%5.0f","Arial#14b",1,num_visents);
		digits(130,32,"tri%5.0fk","Arial#14b",0.001,num_vistriangles);
		digits(130,42,"par%5.0f","Arial#14b",1,num_particles);
		digits(130,52,"lit%5.0f","Arial#14b",1,num_lights);
		digits(130,62,"snd%5.0f","Arial#14b",1,def_dsnd);
		digits(130,72,"fnc%5.0f","Arial#14b",1,num_actions);
		digits(130,82,"bdy%5.0f","Arial#14b",1,num_bodies);

		digits(200,2,"memory MB","Arial#14b",0,0);
		digits(200,12,"nex%5.0f","Arial#14b",1,nexus);
		digits(200,22,"mem%5.0f","Arial#14b",1,sys_memory);
		digits(200,32,"geo%5.0f","Arial#14b",1,d3d_texsurfs);
		digits(200,42,"shd%5.0f","Arial#14b",1,d3d_texsmaps);
		digits(200,52,"ent%5.0f","Arial#14b",1,d3d_texskins);
		digits(200,62,"fre%5.0f","Arial#14b",1,d3d_texfree);
	}

	void def_box(var x1,var y1,var x2,var y2,VECTOR* color)
	{
		draw_line(vector(x1,y1,0),NULL,100);
		draw_line(vector(x2,y1,0),color,100);
		draw_line(vector(x2,y2,0),color,100);
		draw_line(vector(x1,y2,0),color,100);
		draw_line(vector(x1,y1,0),color,100);
	}

	var def_oldmouse = 0;

	void def_debug() 
	{
		if(key_alt) 
		{ 
			diag_status(); 
			return; 
		}
		
		if(key_shift) 
		{
			diag_status();
			freeze_mode = !freeze_mode;
			if (freeze_mode) {
				def_oldmouse = mouse_mode;
				mouse_mode = 4;
				mouse_pointer = 2;
				} else {
				mouse_mode = def_oldmouse;
			}
			while (freeze_mode) {
				if(mouse_left)
				watched = mouse_ent;
				wait(1);
			}
			return;
		}

		if (key_ctrl) {
			toggle(viewMap,SHOW);
			while is(viewMap,SHOW) {
				vec_set(&viewMap->x,&camera->x);
				viewMap->z += 10000;
				wait(1);
			}
			return;
		}
		
		if(d3d_lines) {
			reset(def_debug_pan,SHOW);
			d3d_lines = 0;
			diag_mode &= ~1;
			} else {
			if is(def_debug_pan,SHOW) {
				d3d_lines = 3;
				} else {
				set(def_debug_pan,SHOW);
				diag_mode |= 1;
				while is(def_debug_pan,SHOW) {
					def_dfps = 0.9*def_dfps+0.1/time_frame;
					def_dtps = 0.9*def_dtps+0.1*num_vistriangles/time_frame;
					def_dtlv = time_level+time_sky;
					def_dtcs = time_client+time_server;
					def_dtrf = time_update+time_idle;
					def_dtac = time_actions+time_pfuncs;
					def_dsnd = num_mediastreams + num_sounds;
					def_cang.pan = cycle(camera->pan,0,360); 
					def_cang.tilt = cycle(camera->tilt,-180,180); 
					def_cang.roll = cycle(camera->roll,-180,180); 
					def_box(def_debug_pan->pos_x-3,def_debug_pan->pos_y-2,
					def_debug_pan->pos_x+314,def_debug_pan->pos_y+103,
					vector(255,255,255));
					
					wait(1);
				}
			}
		}
	}

	var def_shot_num = 0;
	void def_shot() 
	{ 
		file_for_screen("shot_",def_shot_num); 
		def_shot_num++; 
	}

	void def_save() 
	{ 
		game_save(app_name,1,SV_ALL-SV_INFO); 
	}

	void def_load() 
	{ 
		game_load(app_name,1); 
	}

	void def_video() 
	{
		var mode = video_mode;
		while(1) {
			if (!key_shift) 
			mode++; 
			else 
			mode--;
			mode = cycle(mode,6,12); 
			if (video_switch(mode,0,0)) 
			break;
		}
	}

	void def_screen() 
	{
		if (!key_alt) 
		return;
		var mode = video_screen + 1;
		if (mode > 2) 
		mode = 1;
		if (video_switch(0,0,mode) == 0) {
			
			printf("This video mode is not supported.");
			
		}
	}

	TEXT* def_ctxt = { font = "Arial#15b"; string("Console","#80"); layer = 999; }

	void def_console() /* ~ */
	{
		def_ctxt->pos_x = 2;
		def_ctxt->pos_y = screen_size.y/4;
		toggle(def_ctxt,SHOW);
		while is(def_ctxt,SHOW) {
			inkey((def_ctxt->pstring)[1]);
			if (13 == result) {
				void* found = var_for_name((def_ctxt->pstring)[1]);
				if (!found) execute((def_ctxt->pstring)[1]);
			} else
			reset(def_ctxt,SHOW);
		}
	}

	TEXT* def_dtxt = {
		pos_x = 2; pos_y = 2; layer = 999;
		string = watch_str;
		flags = SHOW;
	}

	void def_startup() 
	{ 
		if (!on_f2) on_f2 = def_save;
		if (!on_f3) on_f3 = def_load;
		if (!on_f5) on_f5 = def_video;
		if (!on_f6) on_f6 = def_shot;
		if (!on_f11) on_f11 = def_debug;
		
		if (!on_enter) on_enter = def_screen;
		if (!on_grave) on_grave = def_console;
		
		//		if (!on_close) on_close = def_exit;
	}

#endif
