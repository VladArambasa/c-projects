#include "../master.h"

FILE* open_binary_file(const char *filename)
{
	/* RETURN FILE HANDLE */
	return fopen(filename,"rb");
}

/* EXPAND PATH (i.e. ~ to HOME) --- LINUX ONLY */
char* expand_path(const char* path)
{
	if(path[0] == '~')
	{
		/* GET HOME FROM ENV */
		const char* home = getenv("HOME");
		/* FULL PATH STRING */
		static char fullpath[512];
		/* MAKES A STRING AS IT WOULD BE WITH PRINTF FORMATTING */
		snprintf(fullpath,sizeof(fullpath), "%s%s", home, path + 1);
		/* RETURN FULL PATH */
		return fullpath;
	}
	return (char*) path;
}
