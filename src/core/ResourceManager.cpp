#include "core/ResourceManager.h"
#include "fonts/roboto_font.h"

void ResourceManager::LoadFonts()
{
	const char *charSet =
		" !\"#$%&'()*+,-./0123456789:;<=>?@"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"[\\]^_`"
		"abcdefghijklmnopqrstuvwxyz"
		"{|}~"
		"ąćęłńóśżźĄĆĘŁŃÓŚŻŹ";

	int glyphCount = 0;
	int *codepoints = LoadCodepoints(charSet, &glyphCount);

	mainFont = LoadFontFromMemory(".ttf",
		resources_fonts_Roboto_Regular_ttf,
		resources_fonts_Roboto_Regular_ttf_len,
		40,
		codepoints,
		glyphCount);

	UnloadCodepoints(codepoints);
}

