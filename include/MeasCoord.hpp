#ifndef _MEASCOORD_H_
#define _MEASCOORD_H_

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<numeric>
#include<cmath>
#include<math.h>
#include<time.h>
#include<vector>
#include<TCanvas.h>
#include<TGraph.h>
#include<TRandom.h>
#include<TF1.h>
#include<TH1.h>
#include<TH2.h>
#include<TTree.h>
#include<TFile.h>
#include<TNtuple.h>
#include<TGraphErrors.h>
#include<TText.h>
#include<TString.h>
#include<TEnv.h>
#include<TStyle.h>
#include<TAxis.h>
#include<TMath.h>
#include<TMatrixD.h>
#include <TLegend.h>
#include <TRint.h>
#include <TCut.h>
#include <TStyle.h>

#include <EdbDataSet.h>
#include <EdbEDAUtil.h>
#include <EdbVertex.h>
#include <EdbEDA.h>

class MeasCoord {

    public:
        MeasCoord();
        ~MeasCoord();
        void ShowPara();
        void ShowZ();
        void SetMotMCPara(double first_mom, double first_smear);
        std::pair<double, double> CalcTrackAngle(EdbTrackP* t, int index);
        double CalcTrackAngleDiff(EdbTrackP* t, int index);
        double CalcTrackAngleDiffMax(EdbTrackP* t);
        // void VertexSetTrackVector(EdbPVRec *pvr);
        // void DataSetTrackVector(EdbPVRec *pvr);
        void SetZArray(char* fname);
        int SetTrackArray(EdbTrackP *t, int file_type);
        void CalcDataPosDiff(EdbTrackP *t, int plate_num);
        void DrawDataMomGraphCoord(EdbTrackP *t, TCanvas *c1, TNtuple *nt, TString file_name, int plate_num);
        void CalcDataMomCoord(EdbTrackP *t, TCanvas *c1, TNtuple *nt, TString file_name, int file_type);

        // member function
    private:
        // plate number 48 ~ 142
        // static const int nseg;  //number of segments
        // static const int icellMax;  //maximum of cell length
        int nseg;  //number of segments
        int icellMax;  //maximum of cell length
        int icell_cut;
        double ini_mom;
        double smearing;  //smearing (micron)
        // double X0 = 4.677;  //mm in compaund radiation length
        // double zW = 1.0;  //thickness of tungusten plate
        double X0;  //mm in compaund radiation length
        double zW;  //thickness of tungusten plate
        double z;
        char *type;
        char *cal_s; // modify log, radiation length and typeAB error
        // std::vector<EdbTrackP*> v_TrackP;  //keep EdbTrackP
        double cal_CoordArray[40]; // Coordでs_rmsをtrack,cell lengthに入れてる
        double zArray[300];
        double track_array[300][3];
        double delta_array[600];
        int allentryArray[40]; // keep allentry
        int nentryArray[40];
};

#endif