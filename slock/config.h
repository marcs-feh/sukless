/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#171717",     /* after initialization */
	[INPUT] =  "#81aece",			/* during input */
	[FAILED] = "#171717",			/* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;
