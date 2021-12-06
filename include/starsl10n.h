#ifndef STARSL10N_H
#define STARSL10N_H

#ifdef ENGLISH

#define SUN 			L"sun"
#define MOON 			L"moon"
#define RISING 			L"rising"
#define ASCENDANT		L"ascendant"
#define MERCURY			L"mercury"
#define VENUS 			L"venus"
#define MARS 			L"mars"
#define JUPITER		    L"jupiter"
#define SATURN 			L"saturn"
#define URANUS 			L"uranus"
#define NEPTUNE			L"neptune"
#define TNODE 			L"true node"
#define PLUTO			L"pluto"

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

#elif defined(RUSSIAN)

#define SUN 			L"солнце"
#define MOON 			L"луна"
#define RISING 			L"?"
#define ASCENDANT		L"?"
#define MERCURY			L"меркурий"
#define VENUS 			L"венера"
#define MARS 			L"марс"
#define JUPITER		    L"юпитер"
#define SATURN 			L"сатурн"
#define URANUS 			L"уран"
#define NEPTUNE			L"нептун"
#define PLUTO			L"плутон"
#define TNODE 			L"восходящий узел" /****/

#define ARIES			L"овен"
#define TAURUS			L"телец"
#define GEMINI			L"близнецы"
#define CANCER			L"рак"
#define LEO				L"лев"
#define VIRGO			L"дева"
#define LIBRA			L"весы"
#define SCORPIO			L"скорпион"
#define SAGITTARIUS		L"стрелец"
#define CAPRICORN		L"козерог"
#define AQUARIUS		L"водолей"
#define PISCES			L"рыбы"

#define FIRE			L"fire"
#define EARTH			L"earth"
#define AIR				L"духа"
#define WATER			L"вода"

#define MUTABLE			L"mutable"
#define CARDINAL		L"cardinal"
#define FIXED			L"fixed"

#define CONJUNCTION		L"соединение"
#define SEXTILE			L"секстиль"
#define SQUARE			L"квадрат"
#define TRINE			L"тригон"
#define OPPOSITION		L"оппозиция"
#define QUINCUNX		L"квиконс"
#define SEMISEXTILE		L"семисекстиль"

#define HOUSE			L"дом"
#define ONESUFF			L"-й"
#define TWOSUFF			L"-й"
#define THREESUFF		L"-й"
#define NTHSUFF			L"-й"

#define SEXN_CNAME		L"нет"
#define SEXF_CNAME		L"женский род"
#define SEXM_CNAME		L"мужской род"

#define SEXN_NOM		L"он"
#define SEXF_NOM		L"она"
#define SEXM_NOM		L"он"

#define SEXN_ACC		L"его"
#define SEXF_ACC		L"её"
#define SEXM_ACC		L"его"

#define SEXN_DAT		L"ему"
#define SEXF_DAT		L"ей"
#define SEXM_DAT		L"ему"

#define SEXN_GEN		L"его"
#define SEXF_GEN		L"её"
#define SEXM_GEN		L"его"

#define SEXN_INST		L"с нем"
#define SEXF_INST		L"с ней"
#define SEXM_INST		L"с нем"

#define SEXN_POSSM		L"его"
#define SEXF_POSSM		L"её"
#define SEXM_POSSM		L"его"

#define SEXN_POSSF		L"его"
#define SEXF_POSSF		L"её"
#define SEXM_POSSF		L"его"

#define SEXN_POSSN		L"его"
#define SEXF_POSSN		L"её"
#define SEXM_POSSN		L"его"

#define SEXN_POSSP		L"его"
#define SEXF_POSSP		L"её"
#define SEXM_POSSP		L"его"

#define BIRTHCHARTFOR	L"Расчет натальной карты"
#define BORNAT			L"родился/родилась"
#define L_ON			L"в"

#define PROGUSAGE		L"пользование:	stars -H [профиль]\n\
		stars [-dtz] [астральное тело]\n\
		stars -b [-dglqQtvz] [имя]\n\
		stars -H [-1dnz] [имя]\n\
		stars -i (вопрос)\n"

/* need to translate these */
#define PROGHELP		L"\
Arguments:\n\
    -1                    Вместе с -H, показать гороскоп только в том случае, если вы еще не получили его сегодня.\n\
    -b                    Добавить новый астрологический профиль и вывести карту рождения.\n\
    -d ММ/ДД/ГГГГ         Вместе с -b, устанавливить дату рождения для нового профиля. В противном случае предоставить информацию на конкретную дату вместо сегодняшнего дня.\n\
    -g [F/M/N][F/M/N]     Вместе с -b, установить пол профиля и пол предпочтительных партнеров соответственно (женщина-мужчина-нейтральный / безразлично).\n\
    -h                    Показать эту помощь.\n\
    -H                    Получить текущие транзиты и гороскоп для определенного профиля.\n\
    -i (ТЕМА)             Получить информацию на TЕМУ (есть много тем, связанных с астрологией). Если тема не указана, перечислить возможные темы.\n\
    -l ШИРОТА,ДОЛГОТА     Вместе с -b, установить широту и долготу рождения для нового профиля.\n\
    -q                    Вместе с -b, создать краткую сводку карты рождения, состоящую только из Солнца, Луны, Восхода, Меркурия, Марса и Венеры.\n\
    -Q                    Вместе с -b, сохранить профиль, без вывода.\n\
    -t ЧЧ:ММ:СС           Вместе с -b, установить время рождения для нового профиля. В противном случае установить время дня для выполняемой функции.\n\
    -v                    Вместе с -b, составить подробную карту рождения (включая все дома, истинный узел, темную луну / Лилит, Эрис, Цереру и Хирон).\n\
    -z ЧАСОВОЙ_ПОЯС       Все время переводить и печатать в ЧАСОВОМ_ПОЯСЕ, а не по местному времени.\n\
Создано lyndsay <lyndsay@vivaldi.net> для 9front. Лицензия распростронения: MIT.\n"

#define ERROR_ARGUMENT		L"неправильное количество параметров (см. stars(1) или введите stars -h)"
#define ERROR_GENDERFMT		L"непонятный -g параметр"
#define ERROR_NOWIKI		L"вики не установлено"
#define ERROR_PERMISSIONS	L"нет доступа к файлу"
#define ERROR_TIMEFMT		L"неправильный формат времени"
#define ERROR_TIMEZONE		L"ошибка в часовом поясе"
#define ERROR_USAGE			L"неопознанный флажок"

#endif

#endif
