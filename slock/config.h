/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#1e1e1e",     /* after initialization */
	[INPUT] =  "#5197d0",			/* during input */
	[FAILED] = "#1e1e1e",			/* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;
