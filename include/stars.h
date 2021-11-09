/* include u.h BEFORE stars.h or you will get errors */

#ifndef STARS_H
#define STARS_H

#include "starsl10n.h"

typedef struct sign{
	char *name;
	Rune symbol;
	double startd;
	double endd;
	
	struct sign *ari={
		.name=ARIES,
		.symbol=L'♈',
		.startd=0.0,
		.endd=30.0
	};
	struct sign *tau={
		.name=TAURUS,
		.symbol=L'♉',
		.startd=30.0,
		.endd=60.0
	};
	struct sign *gem={
		.name=GEMINI,
		.symbol=L'♊',
		.startd=60.0,
		.endd=90.0
	};
	struct sign *can={
		.name=CANCER,
		.symbol=L'♋',
		.startd=90.0,
		.endd=120.0
	};
	struct sign *leo={
		.name=LEO,
		.symbol=L'♌',
		.startd=120.0,
		.endd=150.0
	};
	struct sign *vir={
		.name=VIRGO,
		.symbol=L'♍',
		.startd=150.0,
		.endd=180.0
	};
	struct sign *lib={
		.name=LIBRA,
		.symbol=L'♎',
		.startd=180.0,
		.endd=210.0
	};
	struct sign *sco={
		.name=SCORPIO,
		.symbol=L'♏',
		.startd=210.0,
		.endd=240.0
	};
	struct sign *sag={
		.name=SAGITTARIUS,
		.symbol=L'♐',
		.startd=240.0,
		.endd=270.0
	};
	struct sign *cap={
		.name=CAPRICORN,
		,symbol=L'♑',
		.startd=270.0,
		.endd=300.0
	};
	struct sign *aqu={
		.name=AQUARIUS,
		.symbol=L'♒',
		.startd=300.0,
		.endd=330.0
	};
	struct sign *pis={
		.name=PISCES,
		.symbol=L'♓',
		.startd=330.0,
		.endd=360.0
	};
} Sign;

Sign *signs[]={ Sign.ari, Sign.tau, Sign.gem, Sign.can, Sign.leo, Sign.vir, Sign.lib, Sign.sco, Sign.sag, Sign.cap, Sign.aqu, Sign.pis };

typedef struct planet{
	double N; /* longitude of ascending node */
	double Nc1;
	double Nc2;
    double i; /* inclination to the elliptic */
	double ic1;
	double ic2;
    double w; /* argument of perihelion */
	double wc1;
	double wc2;
    double a; /* mean dist from sun in AU */
	double ac1;
	double ac2;
    double e; /* eccentricity, 0 = circle, 1 = parabola, in btwn = ellipse */
	double ec1;
	double ec2;
    double M; /* mean anomaly */
	double Mc1;
	double Mc2;

    char *name;
	uint id;
    Rune symbol;
	int trweight;
	Sign *ruler;

	struct planet *sun={
		.N=0.0,
		.i=0.0,
		.wc1=282.9404,
		.wc2=.0000470935,
		.a=1.0,
		.ec1=0.016709,
		.ec2 = 0.000000001151,
		.Mc1 = 356.0470,
		.Mc2 = 0.9856002585,
		.name=SUN,
		.id=0,
		.symbol=L'☉',
		.trweight=5,
		.ruler=Sign.leo
	};
	struct planet *mercury={
		.Nc1=48.3313,
		.Nc2=0.0000324587,
		.ic1=7.0047,
		.ic2=0.00000005,
		.wc1=29.1241,
		.wc2=0.0000101444,
		.a=0.387098,
		.ec1=0.205635,
		.ec2=0.000000000559,
		.Mc1=168.6562,
		.Mc2=4.0923344368
		.name=MERCURY,
		.id=1,
		.symbol=L'☿'
		.trweight=3,
		.ruler=Sign.
	};
	struct planet *venus={
		.Nc1=49.5574,
		.Nc2=0.0000211081,
		.ic1=3.3946,
		.ic2=0.0000000275,
		.wc1=54.891,
		.wc2-0.0000138374,
		.a=0.72333,
		.ec1=0.006773,
		.ec2=0.000000001302,
		.Mc1=48.0052,
		.Mc2=1.6021302244,
		.name=VENUS,
		.id=2,
		.symbol=L'♀',
		.trweight=3
	};
	struct planet *moon={
		.Nc1=125.1228,
		.Nc2=-0.0529538083,
		.i=5.1454,
		.wc1=318.0634,
		.wc2=0.1643573223
		.a=60.2666,
		.e=0.054900,
		.Mc1=115.3654,
		.Mc2=13.0649929509
		.name=MOON,
		.id=4,
		.symbol=L'☾',
		.trweight=4
	};
	struct planet *mars={
		.Nc1=49.5574,
		.Nc2=0.0000211081,
		.ic1=1.8497,
		.ic2=0.0000000178
		.wc1=286.5016,
		.wc2=0.0000292961,
		.a=1.523688,
		.ec1=0.093405,
		.ec2=0.000000002516,
		.Mc1=18.6021,
		.Mc2=0.5240207766,
		.name=MARS,
		.id=5,
		.symbol=L'♂',
		.trweight=3
	};
	struct planet *jupiter={
		.Nc1=100.4542,
		.Nc2=0.0000276854,
		.ic1=1.8497,
		.ic2=0.0000000178,
		.wc1=286.5016,
		.wc2=0.0000292961,
		.a=1.523688,
		.ec1=0.093405,
		.ec2=0.000000002516,
		.Mc1=18.6021,
		.Mc2=0.5240207766
		.name=JUPITER,
		.id=7,
		.symbol=L'♃',
		.trweight=3
	};
	struct planet *saturn={
		.Nc1=113.6634,
		.Nc2=0.000023898,
		.ic1=2.4886,
		.ic2=0.0000001081,
		.wc1=339.3939,
		.wc2=0.0000297661,
		.a=9.55475,
		.ec1=0.055546,
		.ec2=0.000000009499,
		.Mc1=316.9670,
		.Mc2=0.0334442282
		.name=SATURN,
		.id=8,
		.symbol=L'♄',
		.trweight=3
	};
	struct planet *uranus={
		.Nc1=74.0005,
		.Nc2=0.000013978,
		.ic1=0.7733,
		.ic2=0.000000019,
		.wc1=96.6612,
		.wc2=0.000030565,
		.ac1=19.18171,
		.ac2=0.0000000745,
		.ec1=0.047318,
		.ec2=0.00000000745,
		.Mc1=142.5905,
		.Mc2=0.011725806,
		.name=URANUS,
		.id=9,
		.symbol=L'♅',
		.trweight=3
	};
	struct planet *neptune={
		.Nc1=131.7806,
		.Nc2=0.000030173,
		.ic1=1.77,
		.ic2=0.0000000255,
		.wc1=272.8461,
		.wc2=0.000006027,
		.ac1=30.05826,
		.ac2=0.00000003313,
		.ec1=0.008606,
		.ec2=0.00000000215,
		.Mc1=260.2471,
		.Mc2=0.005995147,
		.name=NEPTUNE,
		.id=11,
		.symbol=L'♆',
		.trweight=2
	};
	struct planet *pluto={
		.name=PLUTO,
		.id=12,
		.symbol=L'♇',
		.trweight=1
	};
} Planet;

Planet *planets[]={ Planet.sun, Planet.moon, Planet.mercury, Planet.venus, Planet.mars, Planet.jupiter, Planet.saturn, Planet.uranus, Planet.neptune, Planet.pluto };
int planetn=10;

/* pluto is special */
typedef struct pluto{
	double S;
	double P;
	double latecl;
	double longecl;
	double r;
} Pluto;

/* this should provide enough to translate into another language but please send a patch if more grammatical support is needed */
typedef struct sex{
	Rune *cname;
	Rune *nom;
	Rune *acc;
	Rune *dat;
	Rune *gen;
	Rune *inst;
	Rune *possm;
	Rune *possf;
	Rune *possn;
	Rune *possp;

	struct sex *dontcare={
		.cname=	SEXN_CNAME,
		.nom=	SEXN_NOM  ,
		.acc=	SEXN_ACC  ,
		.dat=	SEXN_DAT  ,
		.gen	SEXN_GEN  ,
		.inst=	SEXN_INST ,
		.possm=	SEXN_POSSM,
		.possf=	SEXN_POSSF,
		.possn=	SEXN_POSSN,
		.possp=	SEXN_POSSP
	};
	struct sex *broad={
		.cname=	SEXF_CNAME,
		.nom=	SEXF_NOM  ,
		.acc=	SEXF_ACC  ,
		.dat=	SEXF_DAT  ,
		.gen	SEXF_GEN  ,
		.inst=	SEXF_INST ,
		.possm=	SEXF_POSSM,
		.possf=	SEXF_POSSF,
		.possn=	SEXF_POSSN,
		.possp=	SEXF_POSSP
	};
	struct sex *moid={
		.cname=	SEXM_CNAME,
		.nom=	SEXM_NOM  ,
		.acc=	SEXM_ACC  ,
		.dat=	SEXM_DAT  ,
		.gen	SEXM_GEN  ,
		.inst=	SEXM_INST ,
		.possm=	SEXM_POSSM,
		.possf=	SEXM_POSSF,
		.possn=	SEXM_POSSN,
		.possp=	SEXM_POSSP
	};
} Sex;

typedef struct trtype{
    Rune symbol;
    Rune *longname;
    double degexact;
	double majorbrange;
	double minorbrange;
	int weight;
	
	struct trtype *conjunct={
		.symbol=L'☌',
		.longname=CONJUNCTION,
		.degexact=0.0,
		.majorbrange=10.0,
		.minorbrange=8.0,
		.weight=6
	};
	struct trtype *opposition={
		.symbol=L'☍',
		.longname=OPPOSITION,
		.degexact=180.0,
		.majorbrange=10.0,
		.minorbrange=6.0,
		.weight=5
	};
	struct trtype *square={
		.symbol=L'□',
		.longname=SQUARE,
		.degexact=90.0,
		.majorbrange=10.0,
		.minorbrange=6.0,
		.weight=4
	};
	struct trtype *sextile={
		.symbol=L'⚹',
		.longname=SEXTILE,
		.degexact=60.0,
		.majorbrange=4.0,
		.minorbrange=3.0,
		.weight=2
	};
	struct trtype *trine={
		.symbol=L'△',
		.longname=TRINE,
		.degexact=120.0,
		.majorbrange=10.0,
		.minorbrange=6.0,
		.weight=3
	};
	struct trtype *semisxt={
		.symbol=L'⚺',
		.longname=SEMISEXTILE,
		.degexact=30.0,
		.majorbrange=1.2,
		.minorbrange=1.2,
		.weight=1
	};
	struct trtype *quincunx={
		.symbol=L'⚻',
		.longname=QUINCUNX,
		.degexact=150.0,
		.majorbrange=3.5,
		.minorbrange=3.5,
		.weight=1
	};
} Trtype;

Trtype *trtypes[]={ Trtype.conjunct, Trtype.opposition, Trtype.square, Trtype.trine, Trtype.sextile, Trtype.trine, Trtype.semisxt, Trtype.quincunx };

typedef struct transit{
	Trtype *type;
	double orb;
	double t;
	Planet *p1;
	Planet *p2;
} Transit;

#define NC '\0'

/* conversion functions */
double rad2deg(double);
double deg2rad(double);

/* make sure degrees are between 0 and 360 */
void degnorm(double);

/* for transits, keep less than 180 */
void degnorm2(double);

/* y = year, m = month, d = date, utc must be hours with subunits as decimals) */
double getday(int y, int m, int d, ulong t);

/* we internally represent the time of day in number of seconds since midnight UTC - easier that way */
ulong tconv(char *fmt, Tzone *tz);

/* sidereal time for a time - use getday() first */
double gmst(double);

/* local sidereal time */
double lst(double tm, double lng);

/* longitude of the perihelion */
double longperi(Planet*);

/* mean longitude */
double meanlong(Planet*);

/* perihelion distance */
double perdist(Planet*);

/* aphelion distance */
double aphdist(Planet*);

/* orbital period */
double orbper(Planet*);

/* obliquity of the ecliptic, for Earth */
double ecl(double day);

/* eccentric anomaly E: requires a filled planet */
double eccano(Planet *p, double d);

/* true anomaly v: requires a filled planet */
double truano(Planet *p, double d);

/* location of mc/midheaven */
double midheaven(double d, double lng);

/* create a time-dependent iteration from planet template */
Planet *planetiter(Planet*, double);
Pluto *plutoiter(double);

/* sign retrieval functions - double is a time from getday() */
Sign *getsign(Planet*, double);
Sign *getplutosign(double);
Sign *getrising(double);
Sign *getmc(double);
Sign *getdc(double);
Sign *getic(double);
Sign **gethouses(double);

/* print a birth chart to stdout and create profile */
void bchart(char *t, uint d, uint m, uint y, double lat, double lng, Sex *ps, Sex *us, int verbosity, Rune *name);

/* print to stdout a list of wiki pages */
void wikilist(void);

/* print to stdout the formatted contents of a wiki page */
void showpage(char *pagename);

/* returns 1 if the planets are in the specified transit type, 0 if not */
int matchestr(double pstart, double pnow, Trtype *t, int major);

/* provides an unsorted set of transits at a given time for a comparison set of planets */
Transit **rawtransits(Planet *birthplanets[], double d);

#endif