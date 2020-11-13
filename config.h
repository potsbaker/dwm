static const unsigned int borderpx    = 2;
static const unsigned int snap        = 8;
static const unsigned int gappx       = 6;
static const int showbar              = 1;
static const int topbar               = 1;
static const int horizpadbar          = 6;
static const int vertpadbar           = 12;
static const char *fonts[]            = {"Mononoki Nerd Font:size=10:antialias=true:autohint=true",
                                         "Hack:size=8:antialias=true:autohint=true",
                                         "JoyPixels:size=10:antialias=true:autohint=true"
                                                                                };
static const char col_gray1[]         = "#121212";
static const char col_gray2[]         = "#121212";
static const char col_alpha[]         = "#E7A66C";
static const char col_gray3[]         = "#303030";
static const char col_gray4[]         = "#121212";
static const char col_cyan[]          = "#121212";
static const char col_desel[]         = "#878787";
/*
static const char col_backg[]         = "#B14A7A";
*/
static const char col_backg[]         = "#E7A66C";
static const unsigned int baralpha    = 0xee;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]        = {
        [SchemeNorm] = { col_desel, col_gray1, col_alpha },
        [SchemeSel]  = { col_gray4, col_backg,  col_backg },
};
static const unsigned int alphas[][3] = {
        [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
        [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };

static const Rule rules[] = {
        { "Gimp",     NULL,       NULL,       0,            1,           -1 },
        { "Firefox",  NULL,       NULL,       1 << 9,       0,           -1 },
};

static const float mfact     = 0.50;
static const int nmaster     = 1;
static const int resizehints = 0;

#include "layouts.c"
static const Layout layouts[] = {
        { "[]=",      tile },
        { "><>",      NULL },
        { "[M]",      monocle },
        { "HHH",      grid },
        { NULL,       NULL },
};

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
        { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
        { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *dmenucmd[]    = { "dmenu_run", "-p", "Run: ", NULL };
static const char *termcmd[]     = { "st", NULL };
static const char *firefoxcmd[]  = { "firefox", NULL };

static Key keys[] = {
        { MODKEY,               XK_p,      spawn,          {.v = dmenucmd } },
        { MODKEY|ShiftMask,     XK_Return, spawn,          {.v = termcmd } },
        { MODKEY,               XK_w,      spawn,          {.v = firefoxcmd } },
        { MODKEY,               XK_b,      togglebar,      {0} },
        { MODKEY|ShiftMask,     XK_j,      rotatestack,    {.i = +1 } },
        { MODKEY|ShiftMask,     XK_k,      rotatestack,    {.i = -1 } },
        { MODKEY,               XK_j,      focusstack,     {.i = +1 } },
        { MODKEY,               XK_k,      focusstack,     {.i = -1 } },
        { MODKEY,               XK_comma,  incnmaster,     {.i = +1 } },
        { MODKEY,               XK_period, incnmaster,     {.i = -1 } },
        { MODKEY,               XK_h,      setmfact,       {.f = -0.05} },
        { MODKEY,               XK_l,      setmfact,       {.f = +0.05} },
        { MODKEY|ControlMask,   XK_Return, zoom,           {0} },
        { MODKEY,               XK_Tab,    view,           {0} },
        { MODKEY|ShiftMask,     XK_c,      killclient,     {0} },

        { MODKEY,               XK_Tab,    cyclelayout,    {.i = -1 } },
        { MODKEY|ShiftMask,     XK_Tab,    cyclelayout,    {.i = +1 } },
        { MODKEY,               XK_space,  setlayout,      {0} },
        { MODKEY|ShiftMask,     XK_space,  togglefloating, {0} },

        { MODKEY,               XK_t,      setlayout,      {.v = &layouts[0]} },
        { MODKEY,               XK_f,      setlayout,      {.v = &layouts[1]} },
        { MODKEY,               XK_m,      setlayout,      {.v = &layouts[2]} },
        { MODKEY,               XK_g,      setlayout,      {.v = &layouts[3]} },

        { MODKEY,               XK_0,      view,           {.ui = ~0 } },
        { MODKEY|ShiftMask,     XK_0,      tag,            {.ui = ~0 } },

        { Mod4Mask,             XK_1,      focusmon,       {.i = -1 } },
        { Mod4Mask,             XK_2,      focusmon,       {.i = +1 } },
        { Mod4Mask|ShiftMask,   XK_1,      tagmon,         {.i = -1 } },
        { Mod4Mask|ShiftMask,   XK_2,      tagmon,         {.i = +1 } },

        TAGKEYS(                  XK_1,          0)
        TAGKEYS(                  XK_2,          1)
        TAGKEYS(                  XK_3,          2)
        TAGKEYS(                  XK_4,          3)
        TAGKEYS(                  XK_5,          4)
        TAGKEYS(                  XK_6,          5)
        TAGKEYS(                  XK_7,          6)
        TAGKEYS(                  XK_8,          7)
        TAGKEYS(                  XK_9,          8)
        { MODKEY|ShiftMask,       XK_q,    quit,           {0} },
        { MODKEY|ShiftMask,       XK_r,    quit,           {1} },
};

static Button buttons[] = {
        { ClkLtSymbol,     0,           Button1,        setlayout,      {0} },
        { ClkLtSymbol,     0,           Button3,        setlayout,      {.v = &layouts[2]} },
        { ClkWinTitle,     0,           Button2,        zoom,           {0} },
        { ClkStatusText,   0,           Button2,        spawn,          {.v = termcmd } },
        { ClkClientWin,    MODKEY,      Button1,        movemouse,      {0} },
        { ClkClientWin,    MODKEY,      Button2,        togglefloating, {0} },
        { ClkClientWin,    MODKEY,      Button3,        resizemouse,    {0} },
        { ClkTagBar,       0,           Button1,        view,           {0} },
        { ClkTagBar,       0,           Button3,        toggleview,     {0} },
        { ClkTagBar,       MODKEY,      Button1,        tag,            {0} },
        { ClkTagBar,       MODKEY,      Button3,        toggletag,      {0} },
};
