#include <bio.h>
#include <u.h>
#include <libc.h>

#include "stars.h"

double
rad2deg(double rad)
{
    return deg*(180/PI);
}

double
deg2rad(double rad)
{
	return rad*(PI/180);
}

void
degnorm(double deg)
{
	if(deg<0){
		deg=360+deg;
	} else {
		while(deg>360){
			deg=deg-360;
		}
	}
}

void
degnorm2(double deg){
	degnorm(deg);
	if(deg>180)
		deg=deg-180;
}

double
getday(int y, int m, int d, ulong t)
{
    return (double) (367*y-7*(y+(m+9)/12)/4-3*((y+(m-9)/7)/100+1)/4+275*m/9+D-730515)+((double)t/(24*360));
}

ulong
tconv(char *fmt, Tzone *tz)
{
	Tm rt;
	Tm *prt;
	tmparse(prt, "hh:mm:ss", fmt, tz, nil);
	vlong nt=tmnorm(prt);
	tmtime(prt, nt, tz);
	return (ulong)(rt.hour*360+rt.min*60+rt.sec);
}

double
gmst(double tm){
	Planet *sp=planetiter(Planet.sun, tm);
	double gmst0=sp->M+sp->w+180;
	return gmst0/15+tm;
}

double
lst(double tm, double lng){
	return (gmst(tm)*15+lng)/15;
}

double
longperi(Planet *p)
{
    return p->n+p->w;
}

double
meanlong(Planet *p)
{
    float w1=longperi(p);
	return p->M+w1;
}

double
perdist(Planet *p)
{
    return p->a*(1-p->e);
}

double
aphdist(Planet *p)
{
	return p->a*(1+p->e);
}

double
orbper(Planet *p)
{
    return pow(p->a, 1.5);
}

double
ecl(double day)
{
	return 23.4393-(3.563*pow10(-7))*d;
}

/* eccano() and trueano() adapted by me from Jürgen Giesen's javascript implementation http://www.jgiesen.de/kepler/kepler.html */ 
double
eccano(Planet *p, double d){
	double delta=pow(10,15);
	double E, F;
	double m=p->M/360;
	m=2*PI*(m-floor(m));
	if(p->e<0.8)
		E=m;
	else
		E=PI;
	F=E-p->e*sin(m)-m;
	int i=0;
	while(abs(F)>delta && i<30){
		E=E-F/(1-p->e*cos(E));
		F=E-p->e*sin(E)-m;
		i++;
	}
	E=rad2deg(E);
	return round(E*pow(10,15))/pow(10,15));
}

double
truano(Planet *p, double d){
	double E=eccano(p, d);
	double fak=sqrt(1-p->e*p->e);
	return rad2deg(atan2(fak*sin(E), cos(E)-deg2rad(p->e)));
}

double
midheaven(double d, double lng){
	double e=ecl(d);
	degnorm(e);
	double er=deg2rad(e);
	
	Planet *sp=planetiter(Planet.sun, d);
	double E=eccano(sp, d);
	double st=lst(d, lng);
	double str=deg2rad(st*15);

	return atan(tan(str)/cos(er));
}

Planet*
planetiter(Planet *p, double d)
{
	Planet *np = p;
	if(p->N==0)
		np->N=degnorm(p->Nc1+p->Nc2*d);
	if(p->i==0)
		np->i=degnorm(p->ic1+p->ic2*d);
	if(p->w==0)
		np->w=degnorm(p->wc1+p->wc2*d);
	if(p->a==0)
		np->a=degnorm(p->ac1+p->ac2*d);
	if(p->e==0)
		np->e=degnorm(p->ec1+p->ec2*d);
	if(p->M==0)
		np->M=degnorm(p->Mc1+p->Mc2*d);
	return np;
}

Pluto*
plutoiter(double d) {
	Pluto np;
	Pluto *pnp=&np;
	pnp->S=degnorm(50.03+0.033459652*d);
	pnp->P=degnorm(238.95+0.003968789*d);
	double radS=deg2rad(pnp->S);
	double radP=deg2rad(pnp->P);
	pnp->latecl=-3.9082-5.453*sin(radP)-14.975*cos(radP)+3.527*sin(2*radP)+1.673*cos(2*radP)-1.051*sin(3*radP)+0.328*cos(3*radP)+0.179*sin(4*radP)-0.292*cos(4*radP)+0.019*sin(5*radP)+0.1*cos(5*radP)-0.031*sin(6*radP)-0.026*cos(6*radP)+0.011*cos(radS-radP); /* sorry */
	pnp->longecl=238.9508+0.00400703*d-19.799*sin(radP)+19.848*cos(radP)+0.897*sin(2*radP)-4.956*cos(2*radP)+0.61*sin(3*radP)+1.211*cos(3*radP)-0.341*sin(4*radP)-0.19*cos(4*radP)+0.128*sin(5*radP)-0.034*cos(5*radP)-0.038*sin(6*radP)+0.031*cos(6*radP)+0.02*sin(radS-radP)-0.01*cos(radS-radP); /* still sorry */
	pnp->r=40.72+6.68*sin(radP)+6.9*cos(radP)-1.18*sin(2*radP)-0.03*cos(2*radP)+0.15*sin(3*radP)-0.14*cos(3*radP);
	return pnp;
}

Sign*
getsign(Planet *p, double d)
{

}

Sign*
getplutosign(double d)
{

}

Sign*
getrising(double d)
{

}

Sign*
getmc(double d)
{

}

Sign*
getdc(double d)
{

}

Sign*
getic(double d)
{
    
}

Sign*
gethouse(int h, double d)
{

}

Sign**
gethouses(double d)
{

}

void
bchart(char *t, uint d, uint m, uint y, double lat, double lng, Sex *ps, Sex *us, int verbosity, Rune *name)
{
	int pdc = open("/lib/stars/profile", OREAD);
	if(dirread(pdc)<0){
		create(pdc, ORDWR, 0650 | DMDIR);
	}
	int nr, nw;
	Biobuf *prof=Bopen("/lib/stars/profile/" name, ORDWR);
	if((nr=Bread(prof, nil, 1))!=1){
		if((nw=Bwrite(prof, &NC, 1))!=1){
			sysfatal(ERROR_PERMISSIONS)
		}
		Rune *fconts = smprint("N%S;T%s;D%lu;M%lu;Y%lu;K%s;L%s;P%S;U%s", name, t, d, m, y, lat, lng, ps->cname, us->cname);
		int clen=runelen(fconts);
		Bwrite(prof, fconts, clen+1);
	} else {
		Rune *fline;
		void *rconts;
		int llen;
		while((Brdline(prof, fline, ';'))!=nil){
			/* not sure if we can rely on runelen given this is not null-terminated */
			llen=0;
			while(fline[llen]!=';') llen++;
			rconts=malloc(llen-1);
			utfecpy(rconts, fline+1, rconts+llen);
			switch(fline[0]){
				case 'N':
					name=rconts;
					break;
				case 'T':
					t=rconts;
					break;
				case 'D':
					d=atoi(rconts);
					break;
				case 'M':
					m=atoi(rconts);
					break;
				case 'Y':
					y=atoi(rconts);
					break;
				case 'K':
					lat=atoi(rconts);
					break;
				case 'L':
					lng=atoi(rconts);
					break;
				case 'P':
					if(rconts==Sex.moid->cname)
						ps=Sex.moid;
					else if(rconts==Sex.broad->cname)
						ps=Sex.broad;
					else
						ps=Sex.dontcare;
					break;
				case 'U':
					if(rconts==Sex.moid->cname)
						us=Sex.moid;
					else if(rconts==Sex.broad->cname)
						us=Sex.broad;
					else
						us=Sex.dontcare;
					break;
				default:
					sysfatal("profile parse failure");
					break;
			}
		}
	}
	if(verbosity>=0){
		print(BIRTHCHARTFOR " %S (" BORNAT " %s " L_ON " %i/%i/%i)\n", name, t, m, d, y);
		ulong realtime=tconv(t, tz);
		double ddc=getday(y, m, d, realtime/360);
		Sign *sunsgn=getsign(Planet.sun, ddc);
		print(L"%S %C: %S %C\n", Planet.sun->name, Planet.sun->symbol, sunsgn->name, sunsgn->symbol);
		Sign *moonsgn=getsign(Planet.moon, ddc);
		print(L"%S %C: %S %C\n", Planet.moon->name, Planet.moon->symbol, moonsgn->name, moonsgn->symbol);
		Sign *risingsgn=getrising(ddc, lat, long);
		print(L"%S ASc: %S %C\n\n", RISING, risingsgn->name, risingsgn->symbol);
		Sign *mercsgn=getsign(Planet.mercury, ddc);
		print(L"%S %C: %S %C\n", Planet.mercury->name, Planet.mercury/symbol, mercsgn->name, mercsgn->symbol);
		Sign *venussgn=getsign(Planet.venus, ddc);
		print(L"%S %C: %S %C\n", Planet.venus->name, Planet.venus->symbol, venussgn->name, venussgn->symbol);
		if(verbosity==2){
			Sign *lilithsgn=getsign(Planet.lilith, ddc);
			print(L"%S %C: %S %C\n", Planet.lilith->name, Planet.lilith->symbol, lilithsgn->name, lilithsgn->symbol);	
		}
		Sign *marssgn=getsign(Planet.mars, ddc);
		print(L"%S \u2642: %S %C\n", Planet.mars->name, marssgn->name, marssgn->symbol);
		if(verbosity==2){
			Sign *ceressgn=getsign(Planet.ceres, ddc);
			print(L"%S %C: %S %C\n", Planet.ceres->name, Planet.ceres->symbol, ceressgn->name, ceressgn->symbol);	
		}
		if(verbosity>0){
			Sign *jupsgn=getsign(Planet.jupiter, ddc);
			print(L"%S %C: %S %C\n", Planet.jupiter->name, Planet.jupiter->symbol, jupsgn->name, jupsgn->symbol);
			Sign *satsgn=getsign(Planet.saturn, ddc);
			print(L"%S %C: %S %C\n", Planet.saturn->name, Planet.saturn->symbol, satsgn->name, satsgn->symbol);
			Sign *ursgn=getsign(Planet.uranus, ddc);
			print(L"%S %C: %S %C\n", Planet.uranus->name, Planet.uranus->symbol, ursgn->name, ursgn->symbol);
			if(verbosity==2){
				Sign *chisgn=getsign(Planet.chiron, ddc);
				print(L"%S %C: %S %C\n", Planet.chiron->name, Planet.chiron->symbol, chisgn->name, chisgn->symbol);
			}
			Sign *neptsgn=getsign(Planet.neptune, ddc);
			print(L"%S %C: %S %C\n", Planet.neptune->name, Planet.neptune->symbol, neptsgn->name, neptsgn->symbol);
			Sign *plutosgn=getplutosign(ddc);
			print(L"%S %C: %S %C\n", Planet.pluto->name, Planet.pluto->symbol, plutosgn->name, plutosgn->symbol);
			if(verbosity==2){
				Sign *erissgn=getsign(Planet.eris, ddc);
				print(L"%S %C: %S %C\n\n", Planet.eris->name, Planet.eris->symbol, erissgn->name, erissgn->symbol);
				Sign **houses=gethouses(ddc);
				for(int i=0;houses[i]!=nil;i++){
					print("%i", i+1);
					if(i<1)
						print(ONESUFF " " HOUSE " (" ASCENDANT ")");
					else if(i<2)
						print(TWOSUFF " " HOUSE);
					else if(i<3)
						print(THREESUFF " " HOUSE);
					else 
						print(NTHSUFF " " HOUSE);
					print(": %S %C\n", houses[i]->name, houses[i]->symbol);
				}
			}
		}
	}
}

void
wikilist(void)
{
	int pdc = open("/lib/stars/info", OREAD);
	if(dirread(pdc)<0){
		sysfatal(ERROR_NOWIKI)
	}
	Dir **wikidir;
	if((dirread(pdc, wikidir)==0)
		sysfatal(ERROR_PERMISSIONS);
	int i=0;
	while(wikidir[i]!=nil){
		sprint("%s\n", basename(wikidir[i]->name));
	}
	close(wikifd);
}

void
showpage(char *pagename)
{
	system("man /lib/stars/info/" pagename "*");
}