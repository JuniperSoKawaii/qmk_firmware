#pragma once

#include "quantum.h"
#define LAYOUT_ortho_1x9( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08 \
) \
{ \
	{ k00, k01, k02, k03, k04, k05, k06, k07, k08 } \
}
#define LAYOUT LAYOUT_ortho_1x9
