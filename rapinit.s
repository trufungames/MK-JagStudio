;;
;; RAPTOR INIT FILE
;;
;;
;; Each object (or group of objects) needs to be defined here
;; RAPTOR init (in _RAPT68k) will configure raptor based on below automatically
;; and create a corresponding Object List for the OP to branch to
;;
;;

; MEMORY TRACK STUFF
;

; 15 chars  						'012345678901234'
RAPTOR_MT_app_name:			dc.b	'RAPTOR',0					; Name of Application
							.even
RAPTOR_MT_file_name:		dc.b	'OSSUM',0					; Name of filename to use
							.even

raptor_init_table:
	dc.b	'>RAPTOR<'	; table start flag
	
;	----------------------------------------------------------------------------------------------------------
;	dc.l	VALUE		; RAPTOR variable	; Comment
;	----------------------------------------------------------------------------------------------------------

	dc.b	'LIST'		; initiate list structure

; Sky Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	0,0								; sprite_x						; 16.16 x value to position at
	dc.w	0,0								; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	368								; sprite_width					; width of sprite (in pixels)
	dc.l	160								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	368/2								; sprite_hbox					; width of collision box
	dc.l	160/2								; sprite_vbox					; height of collision box
	dc.l	BMP_SKY							; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	368*160*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	368*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	368*2								; sprite_gwidth					; GFX width (of data)	
	
; Mountain Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	0,0								; sprite_x						; 16.16 x value to position at
	dc.w	104,0							; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	224								; sprite_width					; width of sprite (in pixels)
	dc.l	48								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	224/2							; sprite_hbox					; width of collision box
	dc.l	48/2							; sprite_vbox					; height of collision box 
	dc.l	BMP_MOUNTAINS					; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	224*48*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	224*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	224*2							; sprite_gwidth					; GFX width (of data)	

; Cloud 1 Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	14,0							; sprite_x						; 16.16 x value to position at
	dc.w	16,0							; sprite_y						; 16.16 y value to position at
	dc.w	1,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	144								; sprite_width					; width of sprite (in pixels)
	dc.l	56								; sprite_height					; height of sprite (in pixels)
	dc.l	is_inactive							; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	144/2							; sprite_hbox					; width of collision box
	dc.l	56/2							; sprite_vbox					; height of collision box 
	dc.l	BMP_CLOUD1						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	144*56*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	144*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	144*2							; sprite_gwidth					; GFX width (of data)	

; Cloud 2 Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	200,0							; sprite_x						; 16.16 x value to position at
	dc.w	16,0							; sprite_y						; 16.16 y value to position at
	dc.w	1,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	168								; sprite_width					; width of sprite (in pixels)
	dc.l	56								; sprite_height					; height of sprite (in pixels)
	dc.l	is_inactive							; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	168/2							; sprite_hbox					; width of collision box
	dc.l	56/2							; sprite_vbox					; height of collision box 
	dc.l	BMP_CLOUD2						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	168*56*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	168*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	168*2							; sprite_gwidth					; GFX width (of data)	

; Cloud 3 Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	365,0							; sprite_x						; 16.16 x value to position at
	dc.w	16,0							; sprite_y						; 16.16 y value to position at
	dc.w	1,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	144								; sprite_width					; width of sprite (in pixels)
	dc.l	56								; sprite_height					; height of sprite (in pixels)
	dc.l	is_inactive							; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	144/2							; sprite_hbox					; width of collision box
	dc.l	56/2							; sprite_vbox					; height of collision box 
	dc.l	BMP_CLOUD1						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	144*56*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	144*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	144*2							; sprite_gwidth					; GFX width (of data)	

; Temple (L) Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	100,0							; sprite_x						; 16.16 x value to position at
	dc.w	46,0							; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	80								; sprite_width					; width of sprite (in pixels)
	dc.l	112								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	80/2							; sprite_hbox					; width of collision box
	dc.l	112/2							; sprite_vbox					; height of collision box 
	dc.l	BMP_TEMPLE						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	80*112*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	80*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	80*2							; sprite_gwidth					; GFX width (of data)	

; Temple (R) Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	179,0							; sprite_x						; 16.16 x value to position at
	dc.w	46,0							; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	80								; sprite_width					; width of sprite (in pixels)
	dc.l	112								; sprite_height					; height of sprite (in pixels)
	dc.l	is_inactive							; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	80/2							; sprite_hbox					; width of collision box
	dc.l	112/2							; sprite_vbox					; height of collision box 
	dc.l	BMP_TEMPLE						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	80*112*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	80*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	80*2							; sprite_gwidth					; GFX width (of data)	
	
; Backdrop Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_inactive						; sprite_active					; sprite active flag
	dc.w	-240,0							; sprite_x						; 16.16 x value to position at
	dc.w	0,0								; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	1024							; sprite_width					; width of sprite (in pixels)
	dc.l	240								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	1024/2							; sprite_hbox					; width of collision box
	dc.l	240/2							; sprite_vbox					; height of collision box
	dc.l	BMP_PG_0						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	1024*240*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	1024*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	1024*2							; sprite_gwidth					; GFX width (of data)	

; Scorpion Idle Shadow Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	50,0								; sprite_x						; 16.16 x value to position at
	dc.w	200,0							; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	80								; sprite_width					; width of sprite (in pixels)
	dc.l	32								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	80/2							; sprite_hbox					; width of collision box
	dc.l	32/2							; sprite_vbox					; height of collision box
	dc.l	BMP_SCORPION_IDLE_S					; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	80*32*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	80*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	2								; sprite_animspd				; frame delay between animation changes
	dc.l	6								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	80*2							; sprite_gwidth					; GFX width (of data)	

; Scorpion Idle Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	50,0								; sprite_x						; 16.16 x value to position at
	dc.w	100,0							; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	76								; sprite_width					; width of sprite (in pixels)
	dc.l	134								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	76/2							; sprite_hbox					; width of collision box
	dc.l	134/2							; sprite_vbox					; height of collision box
	dc.l	BMP_SCORPION_IDLE					; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	76*134*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	76*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	2								; sprite_animspd				; frame delay between animation changes
	dc.l	6								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	76*2							; sprite_gwidth					; GFX width (of data)	

; Kano Idle Shadow Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	210,0							; sprite_x						; 16.16 x value to position at
	dc.w	200,0							; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	72								; sprite_width					; width of sprite (in pixels)
	dc.l	32								; sprite_height					; height of sprite (in pixels)
	dc.l	is_inactive						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	72/2							; sprite_hbox					; width of collision box
	dc.l	32/2							; sprite_vbox					; height of collision box
	dc.l	BMP_KANO_IDLE_S						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	72*32*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	72*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	1								; sprite_animspd				; frame delay between animation changes
	dc.l	6								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	72*2							; sprite_gwidth					; GFX width (of data)

; Kano Idle Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	210,0							; sprite_x						; 16.16 x value to position at
	dc.w	100,0							; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	72								; sprite_width					; width of sprite (in pixels)
	dc.l	134								; sprite_height					; height of sprite (in pixels)
	dc.l	is_inactive						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	72/2							; sprite_hbox					; width of collision box
	dc.l	134/2							; sprite_vbox					; height of collision box
	dc.l	BMP_KANO_IDLE						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	72*134*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	72*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	1								; sprite_animspd				; frame delay between animation changes
	dc.l	6								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	72*2							; sprite_gwidth					; GFX width (of data)

; HUD Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	8,0							; sprite_x						; 16.16 x value to position at
	dc.w	8,0								; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	312							; sprite_width					; width of sprite (in pixels)
	dc.l	32								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	312/2							; sprite_hbox					; width of collision box
	dc.l	32/2							; sprite_vbox					; height of collision box
	dc.l	BMP_HUD						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	312*32*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	312*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	312*2							; sprite_gwidth					; GFX width (of data)	

; HUD Left Healthbar Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	11,0							; sprite_x						; 16.16 x value to position at
	dc.w	28,0								; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	112							; sprite_width					; width of sprite (in pixels)
	dc.l	12								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	112/2							; sprite_hbox					; width of collision box
	dc.l	112/2							; sprite_vbox					; height of collision box
	dc.l	BMP_HUD_BAR						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	112*12*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	112*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	112*2							; sprite_gwidth					; GFX width (of data)	

; HUD Right Healthbar Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	206,0							; sprite_x						; 16.16 x value to position at
	dc.w	28,0								; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	112							; sprite_width					; width of sprite (in pixels)
	dc.l	12								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	112/2							; sprite_hbox					; width of collision box
	dc.l	12/2							; sprite_vbox					; height of collision box
	dc.l	BMP_HUD_BAR						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	112*12*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	112*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	112*2							; sprite_gwidth					; GFX width (of data)	

; HUD Left "Scorpion" Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	20,0							; sprite_x						; 16.16 x value to position at
	dc.w	28,0								; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	72							; sprite_width					; width of sprite (in pixels)
	dc.l	12								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	72/2							; sprite_hbox					; width of collision box
	dc.l	12/2							; sprite_vbox					; height of collision box
	dc.l	BMP_HUD_SCORPION						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	72*12*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	72*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	72*2							; sprite_gwidth					; GFX width (of data)	

; HUD Right "Kano" Object
	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
	dc.l	is_active						; sprite_active					; sprite active flag
	dc.w	268,0							; sprite_x						; 16.16 x value to position at
	dc.w	28,0								; sprite_y						; 16.16 y value to position at
	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
	dc.l	40							; sprite_width					; width of sprite (in pixels)
	dc.l	12								; sprite_height					; height of sprite (in pixels)
	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
	dc.l	0								; sprite_coffx					; x offset from center for collision box center
	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
	dc.l	40/2							; sprite_hbox					; width of collision box
	dc.l	12/2							; sprite_vbox					; height of collision box
	dc.l	BMP_HUD_KANO						; sprite_gfxbase				; start of bitmap data
	dc.l	16								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
	dc.l	40*12*2						; sprite_framesz				; size per frame in bytes of sprite data
	dc.l	40*2							; sprite_bytewid				; width in bytes of one line of sprite data
	dc.l	0								; sprite_animspd				; frame delay between animation changes
	dc.l	0								; sprite_maxframe				; number of frames in animation chain
	dc.l	ani_rept						; sprite_animloop				; repeat or play once
	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
	dc.l	no_CLUT							; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
	dc.l	cant_hit						; sprite_colchk					; if sprite can collide with another
	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
	dc.l	1								; sprite_hitpoint				; Hitpoints before death
	dc.l	2								; sprite_damage					; Hitpoints deducted from target
	dc.l	40*2							; sprite_gwidth					; GFX width (of data)	
	
; Template
;	dc.l	1								; (REPEAT COUNTER) 				; Create this many objects of this type (or 1 for a single object)
;	dc.l	is_active						; sprite_active					; sprite active flag
;	dc.w	20,0							; sprite_x						; 16.16 x value to position at
;	dc.w	100,0							; sprite_y						; 16.16 y value to position at
;	dc.w	0,0								; sprite_xadd					; 16.16 x addition for sprite movement
;	dc.w	0,0								; sprite_yadd					; 16.16 y addition for sprite movement
;	dc.l	32								; sprite_width					; width of sprite (in pixels)
;	dc.l	11								; sprite_height					; height of sprite (in pixels)
;	dc.l	is_normal						; sprite_flip					; flag for mirroring data left<>right
;	dc.l	0								; sprite_coffx					; x offset from center for collision box center
;	dc.l	0								; sprite_coffy					; y offset from center for collision box center	
;	dc.l	32/2							; sprite_hbox					; width of collision box
;	dc.l	5/2								; sprite_vbox					; height of collision box
;	dc.l	BMP_PLAYER						; sprite_gfxbase				; start of bitmap data
;	dc.l	4								; (BIT DEPTH)					; bitmap depth (1/2/4/8/16/24)
;	dc.l	is_RGB							; (CRY/RGB)						; bitmap GFX type
;	dc.l	is_trans						; (TRANSPARENCY)				; bitmap TRANS flag
;	dc.l	32*11/2							; sprite_framesz				; size per frame in bytes of sprite data
;	dc.l	32/2							; sprite_bytewid				; width in bytes of one line of sprite data
;	dc.l	3								; sprite_animspd				; frame delay between animation changes
;	dc.l	7								; sprite_maxframe				; number of frames in animation chain
;	dc.l	ani_rept						; sprite_animloop				; repeat or play once
;	dc.l	edge_wrap						; sprite_wrap					; wrap on screen exit, or remove
;	dc.l	spr_inf							; sprite_timer					; frames sprite is active for (or spr_inf)
;	dc.l	spr_linear						; sprite_track					; use 16.16 xadd/yadd or point to 16.16 x/y table
;	dc.l	0								; sprite_tracktop				; pointer to loop point in track table (if used)
;	dc.l	spr_unscale						; sprite_scaled					; flag for scaleable object
;	dc.l	%00100000						; sprite_scale_x				; x scale factor (if scaled)
;	dc.l	%00100000						; sprite_scale_y				; y scale factor (if scaled)
;	dc.l	-1								; sprite_was_hit				; initially flagged as not hit
;	dc.l	1								; sprite_CLUT					; no_CLUT (8/16/24 bit) or CLUT (1/2/4 bit)
;	dc.l	can_hit							; sprite_colchk					; if sprite can collide with another
;	dc.l	cd_keep							; sprite_remhit					; flag to remove (or keep) on collision
;	dc.l	single							; sprite_bboxlink				; single for normal bounding box, else pointer to table
;	dc.l	1								; sprite_hitpoint				; Hitpoints before death
;	dc.l	2								; sprite_damage					; Hitpoints deducted from target
;	dc.l	32/2							; sprite_gwidth					; GFX width (of data)	

	dc.b	'STOP'							; end of the current LIST

	dc.b	'<RAPTOR>'						; table termination flag

; END OF FILE.

	
	
	
