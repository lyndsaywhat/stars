#ifndef STARSL10N_H
#define STARSL10N_H

/* change the definitions in this file and the text in files in stars/info/* to translate program */

#define SUN 			L"sun"
#define MOON 			L"moon"
#define RISING 			L"rising"
#define ASCENDANT		L"ascendant"
#define MERCURY			L"mercury"
#define VENUS 			L"venus"
#define MARS 			L"mars"
#define CERES			L"ceres"
#define JUPITER		    L"jupiter"
#define SATURN 			L"saturn"
#define URANUS 			L"uranus"
#define CHIRON			L"chiron"
#define NEPTUNE			L"neptune"
#define TNODE 			L"true node"

#define ARIES			L"aries"
#define TAURUS			L"taurus"
#define GEMINI			L"gemini"
#define CANCER			L"cancer"
#define LEO				L"leo"
#define VIRGO			L"virgo"
#define LIBRA			L"libra"
#define SCORPIO			L"scorpio"
#define SAGITTARIUS		L"sagittarius"
#define CAPRICORN		L"capricorn"
#define AQUARIUS		L"aquarius"
#define PISCES			L"pisces"

#define FIRE			L"fire"
#define EARTH			L"earth"
#define AIR				L"air"
#define WATER			L"water"

#define MUTABLE			L"mutable"
#define CARDINAL		L"cardinal"
#define FIXED			L"fixed"

#define CONJUNCTION		L"conjunction"
#define SEXTILE			L"sextile"
#define SQUARE			L"square"
#define TRINE			L"trine"
#define OPPOSITION		L"opposition"
#define QUINCUNX		L"quincunx"
#define SEMISEXTILE		L"semisextile"

#define HOUSE			L"house"
#define ONESUFF			L"st"
#define TWOSUFF			L"nd"
#define THREESUFF		L"rd"
#define NTHSUFF			L"th"

#define SEXN_CNAME		L"none"
#define SEXF_CNAME		L"female"
#define SEXM_CNAME		L"male"

#define SEXN_NOM		L"they"
#define SEXF_NOM		L"she"
#define SEXM_NOM		L"he"

#define SEXN_ACC		L"them"
#define SEXF_ACC		L"her"
#define SEXM_ACC		L"him"

#define SEXN_DAT		L"them"
#define SEXF_DAT		L"her"
#define SEXM_DAT		L"him"

#define SEXN_GEN		L"of theirs"
#define SEXF_GEN		L"of hers"
#define SEXM_GEN		L"of his"

#define SEXN_INST		L"with them"
#define SEXF_INST		L"with her"
#define SEXM_INST		L"with him"

#define SEXN_POSSM		L"their"
#define SEXF_POSSM		L"her"
#define SEXM_POSSM		L"his"

#define SEXN_POSSF		L"their"
#define SEXF_POSSF		L"her"
#define SEXM_POSSF		L"his"

#define SEXN_POSSN		L"their"
#define SEXF_POSSN		L"her"
#define SEXM_POSSN		L"his"

#define SEXN_POSSP		L"their"
#define SEXF_POSSP		L"her"
#define SEXM_POSSP		L"his"

#define BIRTHCHARTFOR	L"Birth chart for"
#define BORNAT			L"born at"
#define L_ON			L"on"

/* Don't translate the program name or the flags for these!! I put in a Russian example in the macro PROGUSAGE_RU so you know what it should look like. */
#define PROGUSAGE		L"usage:	stars -H [profile]\n\
       stars [-dtz] [astral body]\n\
	   stars -b [-dglqQtvz] [name]\n\
	   stars -H [-1dz] [name]\n\
	   stars -i (query)\n"
#define PROGUSAGE_RU	L"пользование:	stars -H [профиль]\n\
		stars [-dtz] [астральное тело]\n\
		stars -b [-dglqQtvz] [имя]\n\
		stars -H [-1dnz] [имя]\n\
		stars -i (вопрос)\n"
#define PROGHELP		L"\
Arguments:\n\
	-1					With -H, only output a horoscope if you have not already gotten one today.\n\
	-b					Add a new astrological profile and output birth chart.\n\
	-d MM/DD/YYYY		With -b, sets the date of birth for the new profile. Otherwise, provides information for a particular date instead of today.\n\
	-g [F/M/N][F/M/N]	With -b, set the gender of the profile and the gender of preferred partners respectively (female-male-neutral/don\'t care).\n\
	-h					Show this help.\n\
	-H					Get current transits and horoscope for a particular profile.\n\
	-i (TOPIC)			Get information about TOPIC (there are many topics relating to astrology). If no topic is specified, list possible topics.\n\
	-l LAT,LONG			With -b, set the latitude and longitude of birth for the new profile.\n\
	-q					With -b, produce a quiet birth chart summary, with just Sun, Moon, Rising, Mercury, Mars, and Venus.\n\
	-Q					With -b, produce no output at all, only store a profile.\n\
	-t HH:MM:SS			With -b, set the time of birth for the new profile. Otherwise, set the time of day for the function being performed.\n\
	-v					With -b, produce a verbose birth chart (including all houses, true node, dark moon/Lilith, Eris, Ceres, and Chiron).\n\
	-z TIMEZONE			Interpret and print all times in TIMEZONE instead of local time.\n\
Written by lyndsay <lyndsay@vivaldi.net> for 9front. MIT license.\n"

#define ERROR_ARGUMENT		L"wrong number of arguments (see stars(1) or enter stars -h)"
#define ERROR_GENDERFMT		L"not a recognized -g argument"
#define ERROR_NOWIKI		L"no wiki appears to be installed"
#define ERROR_PERMISSIONS	L"cannot access file (do you have the right permissions?)"
#define ERROR_TIMEFMT		L"incorrect time format"
#define ERROR_TIMEZONE		L"timezone error"
#define ERROR_USAGE			L"unrecognized flag"

#endif