/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 0;        /* 1 means use non-dwm status bar */
static const int user_bh            = 23;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *altbarclass      = "Polybar";/* Alternate bar class name */
static const char *altbarcmd        = "$HOME/bar.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { "monospace:size=11" };

static const char col_bg[]          = "#1e1e1e";
static const char col_fg[]          = "#d4d4d4";

static const char col_black[]       = "#2f2f2f";
static const char col_red[]         = "#dd3838";
static const char col_green[]       = "#7c9b43";
static const char col_yellow[]      = "#edb335";
static const char col_blue[]        = "#5599d0";
static const char col_magenta[]     = "#d073c9";
static const char col_cyan[]        = "#4ec9a7";
static const char col_white[]       = "#dcdcdc";

//static const char dmenufont[]       = "monospace:size=11";
static const char *colors[][3]      = {
	/*                  fg          bg         border    */
	[SchemeNorm]     = { col_fg,    col_bg,     col_black },
	[SchemeSel]      = { col_fg,    col_bg,     col_blue},

    /* NOTE: The last "#000000" elements are not used, but are needed, so leave them as they are */
	[SchemeStatus]   = { col_cyan,        col_bg,     "#000000" },

	[SchemeTagsSel]  = { col_black,     col_yellow, "#000000" },
    [SchemeTagsNorm] = { col_fg,        col_bg,     "#000000" },

    [SchemeInfoSel]  = { col_magenta,   col_bg,     "#000000" },
    [SchemeInfoNorm] = { col_fg,        col_bg,     "#000000" },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
 	{ "[/]",      dwindle },
 	{ "|M|",      centeredmaster },
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
 	{ ">M>",      centeredfloatingmaster },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static char dmenumon[2] = "0";

/* Replacement to the SHCMD macro, which I find to be more concise with the
 * rest of the program, the old one is commented bellow in case you want to
 * replace it */
#define SHCMD(cmd) {"/bin/sh", "-c", cmd, NULL}
/* #define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } } */

/* Execute a command inside a terminal. by dafult st is used, edit this macro
 * accordingly if you use another terminal emulator */
#define TERMCMD(cmd) {"st", "-e", cmd, NULL}

/* commands */
/* NOTE: do not delete or rename the variables: dmenucmd, termcmd */
static const char *dmenucmd[]   = { "dmenu_run", "-h", "23", "-p", "Launch: ", NULL};
static const char *termcmd[]    = { "st", NULL };
static const char *webbrowser[] = { "firefox", NULL };
static const char *htop[]       = TERMCMD("htop");

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
    /* commands */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      spawn,          {.v = webbrowser } },
	{ MODKEY,                       XK_t,      spawn,          {.v = htop } },

    /* dwm controls */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },

	{ MODKEY,                       XK_a,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_s,      zoom,           {0} },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },

	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },

	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },

	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },

	{ MODKEY,                       XK_Tab,    view,           {0} },

    /* layouts */
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_y,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[4]} },

    /* togglealwaysontop should also togglefloating, the inverse isnt needed though */
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,      {0} },
 	{ MODKEY|ShiftMask,             XK_space,  togglealwaysontop,   {0} },

	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
    /* tag keys */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

