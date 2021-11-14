#include <u.h>
#include <libc.h>
#include <string.h>

#include "starsl10n.h"
#include "stars.h"

int mode; /* 0 = planet status, 1 = create profile, 2 = horoscope, 3 = wiki */
Tzone *tz;
char *date;
char *time;
double lat;
double lng;
int verbosity;
int maxh;
Sex *usex;
Sex *psex;

int flag1;

void
main(int argc, char *argv[])
{
	/* set default settings */
	mode=0;

	if((tz=tzload("local")==nil)
		sysfatal(ERROR_TIMEZONE);
	Tm now;
	Tm *pnow=&now;	
	tmnow(pnow, tz);
	Tmfmt *dfmt=tmfmt(pnow, "MM/DD/YYYY");
	Tmfmt *tfmt=tmfmt(pnow, "HH:MM:SS");

	date=smprint("%τ", dfmt);
	time=smprint("%τ", tfmt);
	lat=0.0;
	lng=0.0;
	verbosity=0;
	usex=Sex.dontcare;
	psex=Sex.dontcare;

	char *relrg=nil;
	for(int i=0;i<argc;i++){
		if(argc[i][0]=='-'){
			int len=strlen(argc[i])+1;
			for(int j=1;j<len;j++){
				switch(j){
					case '1':
						flag1++;
						break;
					case 'b':
						mode=1;
						break;
					case 'd':
						if(i==argc-1)
							sysfatal(ERROR_ARGUMENT);
						date=argv[i+1];
						i++;
						break;
					case 'g':
						if(i==argc-1)
							sysfatal(ERROR_ARGUMENT);
						int slen=strlen(argc[i+1]);
						if(slen!=2){
							sysfatal(ERROR_ARGUMENT);
						} else {
							switch(argc[i+1][0]){
								case 'N':
									usex=Sex.dontcare;
									break;
								case 'F':
									usex=Sex.female;
									break;
								case 'M':
									usex=Sex.male;
									break;
								default:
									sysfatal(ERROR_GENDERFMT);
									break;
							}
							switch(argc[i+1][1]){
								case 'N':
									psex=Sex.dontcare;
									break;
								case 'F':
									psex=Sex.female;
									break;
								case 'M':
									psex=Sex.male;
									break;
								default:
									sysfatal(ERROR_GENDERFMT);
									break;
							}
						}
						i++;
						break;
					case 'h':
						help();
						exits(0);
						break;
					case 'H':
						mode=2;
						break;
					case 'i':
						mode=3;
						break;
					case 'l':
						/* split the argument by comma to get latitude + longitude */
						/* "fun" fact: you can do this in C# in three lines... */
						if(i==argc-1)
							sysfatal(ERROR_ARGUMENT);
						int llen=strlen(argv[i+1]);
						int k=0;
						char *tlat;
						char *tlng;
						while(argc[i+1][k]!=','){
							tlat=realloc(lat,k+1);
							tlat[k]=argv[i+1][k];
							k++;
						}
						int l=0;
						while((argv[i+1]+k+1)[l]!='\0'){
							tlng=realloc(lng,l+1);
							tlng[l]=argv[i+1][l];
							l++;
						}
						lat=strtod(tlat);
						lng=strtod(tlng);
						i++;
						break;
					case 'n':
						if(i==argc-1)
							sysfatal(ERROR_ARGUMENT);
						maxh=atoi(argv[i+1]);
						i++;
					case 'q':
						verbosity=0;
						break;
					case 'Q':
						verbosity=-1;
						break;
					case 't':
						if(i==argc-1)
							sysfatal(ERROR_ARGUMENT);
						time=argv[i+1];
						i++;
						break;
					case 'v':
						verbosity=2;
						break;
					case 'z':
						if(i==argc-1)
							sysfatal(ERROR_ARGUMENT);
						if((tz=tzload(argv[i+1]))==nil)
							sysfatal(ERROR_TIMEZONE);
						i++;
						break;
					default:
						usage();
						exits(ERROR_USAGE);
						break;
				}
			}
		} else if(relrg==nil){
			relrg=argv[i];
		} else {
			sysfatal(ERROR_ARGUMENT);
		}
	}
	if(relrg==nil && mode!=3){
		sysfatal(ERROR_ARGUMENT);
	}
	switch(mode){
		case 0:
			planetinfo(relrg, tz, date);
			break;
		case 1:
			Tm rd;
			Tm *prd=&rd;
			if ((prd=tmparse(prd, "MM/DD/YYYY", date, tz, nil))==nil)
				sysfatal(ERROR_TIMEFMT);
			bchart(time, prd->mday, prd->mon, prd->year, tz, lat, long, relrg);
			break;
		case 2:
			hscope(date, time, relrg);
			break;
		case 3:
			if(relrg==nil){
				wikilist();
			} else {
				showpage(relrg);
			}
			break;
		default:
			exits(0);
	}
}