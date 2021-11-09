int
matchestr(double pstart, double pnow, Trtype *t, int major){
    double omin, omax;
    double diff=pnow-pstart;
    degnorm2(diff);

    if(major==1){
        omin=t->degexact-t->majorbrange;
        omax=t->degexact+t->majorbrange;
    } else {
        omin=t->degexact-t->minorbrange;
        omax=t->degexact+t->majorbrange;
    }
    
    if(diff>omin && diff<omax)
        return 1;
    else
        return 0;
}

Transit**
rawtransits(Planet *birthplanets[], double d){
    double bn=sizeof(birthplanets)/sizeof(Planet*);
    double bl, cl;
    double *bloc=&bl;
    double *cloc=&cl;
    Transit t;
    Transit **out;
    int mat, maj, tn;
    tn=0;
    for(int i=0;i<bn;i++){
        *bloc=getloc(birthplanets[i]);
        for(int j=0;j<planetn;j++){
            *cloc=getloc(planets[j]);
            if(j < 2)
                maj=1;
            else
                maj=0;
            for(int k=0;k<transitn;k++){
                if((m=matchestr(*bloc, *cloc, trtypes[k], maj))==1){
                    t={
                        .type=trtypes[k],
                        .orb=abs(trtypes[k]->degexact-(*cloc-*bloc)),
                        .t=d,
                        .p1=birthplanets[i],
                        .p2=planets[j]
                    };
                    out=realloc((tn+1)*sizeof(Transit*));
                    out[tn]=&t;
                    tn++;
                }
            }
        }
    }
    return out;
}

double
transitweight(Transit *t){
    return ((t->p1->trweight + t->p2->trweight)/t->orb+1);
}

void
sorttransits(Transit **){
    
}

int
iscazimi(Transit *tr){
    if(tr.orb < 0.28)
        return 1;
    else
        return 0;
}