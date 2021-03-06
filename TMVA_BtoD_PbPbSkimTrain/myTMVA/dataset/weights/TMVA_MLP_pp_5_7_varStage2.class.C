// Class: ReadMLP
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : MLP::MLP
TMVA Release   : 4.2.1         [262657]
ROOT Release   : 6.08/07       [395271]
Creator        : tawei
Date           : Wed Sep 20 09:33:18 2017
Host           : Linux vocms0302.cern.ch 2.6.32-696.1.1.el6.x86_64 #1 SMP Wed Apr 12 08:44:28 CEST 2017 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /export/d00/scratch/tawei/HeavyFlavor/Run2Ana/BtoDAna/BtoDAnaPbPbRunII/TMVA_BtoD_PbPbSkimTrain/myTMVA
Training events: 712477
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
NCycles: "600" [Number of training cycles]
HiddenLayers: "N+5" [Specification of hidden layer architecture]
NeuronType: "tanh" [Neuron activation function type]
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
VarTransform: "N" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
H: "True" [Print method-specific help message]
TestRate: "5" [Test for overtraining performed at each #th epochs]
UseRegulator: "False" [Use regulator to avoid over-training]
# Default:
RandomSeed: "1" [Random seed for initial synapse weights (0 means unique seed for each run; default value '1')]
EstimatorType: "CE" [MSE (Mean Square Estimator) for Gaussian Likelihood or CE(Cross-Entropy) for Bernoulli Likelihood]
NeuronInputType: "sum" [Neuron input function type]
VerbosityLevel: "Default" [Verbosity level]
CreateMVAPdfs: "False" [Create PDFs for classifier outputs (signal and background)]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
TrainingMethod: "BP" [Train with Back-Propagation (BP), BFGS Algorithm (BFGS), or Genetic Algorithm (GA - slower and worse)]
LearningRate: "2.000000e-02" [ANN learning rate parameter]
DecayRate: "1.000000e-02" [Decay rate for learning parameter]
EpochMonitoring: "False" [Provide epoch-wise monitoring plots according to TestRate (caution: causes big ROOT output file!)]
Sampling: "1.000000e+00" [Only 'Sampling' (randomly selected) events are trained each epoch]
SamplingEpoch: "1.000000e+00" [Sampling is used for the first 'SamplingEpoch' epochs, afterwards, all events are taken for training]
SamplingImportance: "1.000000e+00" [ The sampling weights of events in epochs which successful (worse estimator than before) are multiplied with SamplingImportance, else they are divided.]
SamplingTraining: "True" [The training sample is sampled]
SamplingTesting: "False" [The testing sample is sampled]
ResetStep: "50" [How often BFGS should reset history]
Tau: "3.000000e+00" [LineSearch "size step"]
BPMode: "sequential" [Back-propagation learning mode: sequential or batch]
BatchSize: "-1" [Batch size: number of events/batch, only set if in Batch Mode, -1 for BatchSize=number_of_events]
ConvergenceImprove: "1.000000e-30" [Minimum improvement which counts as improvement (<0 means automatic convergence check is turned off)]
ConvergenceTests: "-1" [Number of steps (without improvement) required for convergence (<0 means automatic convergence check is turned off)]
UpdateLimit: "10000" [Maximum times of regulator update]
CalculateErrors: "False" [Calculates inverse Hessian matrix at the end of the training to be able to calculate the uncertainties of an MVA value]
WeightRange: "1.000000e+00" [Take the events for the estimator calculations from small deviations from the desired value to large deviations only over the weight range]
##


#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-

NVar 6
Dtrk1Pt                       Dtrk1Pt                       Dtrk1Pt                       Dtrk1Pt                                                         'F'    [0.500001788139,7.91416215897]
DRestrk1Pt                    DRestrk1Pt                    DRestrk1Pt                    DRestrk1Pt                                                      'F'    [0.500000298023,8.17114925385]
DRestrk2Pt                    DRestrk2Pt                    DRestrk2Pt                    DRestrk2Pt                                                      'F'    [0.500001132488,7.59029436111]
Dtrk1Dxy/Dtrk1D0Err           Dtrk1Dxy_D_Dtrk1D0Err         Dtrk1Dxy/Dtrk1D0Err           Dtrk1Dxy/Dtrk1D0Err                                             'F'    [-1067.71142578,414.84954834]
DRestrk1Dxy/DRestrk1D0Err     DRestrk1Dxy_D_DRestrk1D0Err   DRestrk1Dxy/DRestrk1D0Err     DRestrk1Dxy/DRestrk1D0Err                                       'F'    [-255.85874939,87.2235031128]
DRestrk2Dxy/DRestrk2D0Err     DRestrk2Dxy_D_DRestrk2D0Err   DRestrk2Dxy/DRestrk2D0Err     DRestrk2Dxy/DRestrk2D0Err                                       'F'    [-189.184921265,143.8074646]
NSpec 0


============================================================================ */

#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

 public:

   // constructor
   IClassifierReader() : fStatusIsClean( true ) {}
   virtual ~IClassifierReader() {}

   // return classifier response
   virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

   // returns classifier status
   bool IsStatusClean() const { return fStatusIsClean; }

 protected:

   bool fStatusIsClean;
};

#endif

class ReadMLP : public IClassifierReader {

 public:

   // constructor
   ReadMLP( std::vector<std::string>& theInputVars ) 
      : IClassifierReader(),
        fClassName( "ReadMLP" ),
        fNvars( 6 ),
        fIsNormalised( false )
   {      
      // the training input variables
      const char* inputVars[] = { "Dtrk1Pt", "DRestrk1Pt", "DRestrk2Pt", "Dtrk1Dxy/Dtrk1D0Err", "DRestrk1Dxy/DRestrk1D0Err", "DRestrk2Dxy/DRestrk2D0Err" };

      // sanity checks
      if (theInputVars.size() <= 0) {
         std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
         fStatusIsClean = false;
      }

      if (theInputVars.size() != fNvars) {
         std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
                   << theInputVars.size() << " != " << fNvars << std::endl;
         fStatusIsClean = false;
      }

      // validate input variables
      for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
         if (theInputVars[ivar] != inputVars[ivar]) {
            std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
                      << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
            fStatusIsClean = false;
         }
      }

      // initialize min and max vectors (for normalisation)
      fVmin[0] = -1;
      fVmax[0] = 1;
      fVmin[1] = -1;
      fVmax[1] = 1;
      fVmin[2] = -1;
      fVmax[2] = 0.99999988079071;
      fVmin[3] = -1;
      fVmax[3] = 1;
      fVmin[4] = -1;
      fVmax[4] = 1;
      fVmin[5] = -1;
      fVmax[5] = 1;

      // initialize input variable types
      fType[0] = 'F';
      fType[1] = 'F';
      fType[2] = 'F';
      fType[3] = 'F';
      fType[4] = 'F';
      fType[5] = 'F';

      // initialize constants
      Initialize();

      // initialize transformation
      InitTransform();
   }

   // destructor
   virtual ~ReadMLP() {
      Clear(); // method-specific
   }

   // the classifier response
   // "inputValues" is a vector of input values in the same order as the 
   // variables given to the constructor
   double GetMvaValue( const std::vector<double>& inputValues ) const;

 private:

   // method-specific destructor
   void Clear();

   // input variable transformation

   double fMin_1[3][6];
   double fMax_1[3][6];
   void InitTransform_1();
   void Transform_1( std::vector<double> & iv, int sigOrBgd ) const;
   void InitTransform();
   void Transform( std::vector<double> & iv, int sigOrBgd ) const;

   // common member variables
   const char* fClassName;

   const size_t fNvars;
   size_t GetNvar()           const { return fNvars; }
   char   GetType( int ivar ) const { return fType[ivar]; }

   // normalisation of input variables
   const bool fIsNormalised;
   bool IsNormalised() const { return fIsNormalised; }
   double fVmin[6];
   double fVmax[6];
   double NormVariable( double x, double xmin, double xmax ) const {
      // normalise to output range: [-1, 1]
      return 2*(x - xmin)/(xmax - xmin) - 1.0;
   }

   // type of input variable: 'F' or 'I'
   char   fType[6];

   // initialize internal variables
   void Initialize();
   double GetMvaValue__( const std::vector<double>& inputValues ) const;

   // private members (method specific)

   double ActivationFnc(double x) const;
   double OutputActivationFnc(double x) const;

   int fLayers;
   int fLayerSize[3];
   double fWeightMatrix0to1[12][7];   // weight matrix from layer 0 to 1
   double fWeightMatrix1to2[1][12];   // weight matrix from layer 1 to 2

   double * fWeights[3];
};

inline void ReadMLP::Initialize()
{
   // build network structure
   fLayers = 3;
   fLayerSize[0] = 7; fWeights[0] = new double[7]; 
   fLayerSize[1] = 12; fWeights[1] = new double[12]; 
   fLayerSize[2] = 1; fWeights[2] = new double[1]; 
   // weight matrix from layer 0 to 1
   fWeightMatrix0to1[0][0] = -0.594818503282609;
   fWeightMatrix0to1[1][0] = -0.029624837867397;
   fWeightMatrix0to1[2][0] = 8.5715339489897;
   fWeightMatrix0to1[3][0] = 0.00632231747153435;
   fWeightMatrix0to1[4][0] = -1.42517307840159;
   fWeightMatrix0to1[5][0] = -3.44590840448356;
   fWeightMatrix0to1[6][0] = 0.367387911232974;
   fWeightMatrix0to1[7][0] = 5.27670647461748;
   fWeightMatrix0to1[8][0] = 2.26176786815094;
   fWeightMatrix0to1[9][0] = 0.982948055620871;
   fWeightMatrix0to1[10][0] = -3.66788117624434;
   fWeightMatrix0to1[0][1] = -9.68349662370301;
   fWeightMatrix0to1[1][1] = 0.0962229119272426;
   fWeightMatrix0to1[2][1] = -0.9614876509629;
   fWeightMatrix0to1[3][1] = 0.184893317435533;
   fWeightMatrix0to1[4][1] = 1.70922118137648;
   fWeightMatrix0to1[5][1] = -3.0082915347678;
   fWeightMatrix0to1[6][1] = 3.59825868393952;
   fWeightMatrix0to1[7][1] = -0.898266265806814;
   fWeightMatrix0to1[8][1] = 4.86726889718188;
   fWeightMatrix0to1[9][1] = -0.118097109409;
   fWeightMatrix0to1[10][1] = -3.88122933118347;
   fWeightMatrix0to1[0][2] = -0.524448471409337;
   fWeightMatrix0to1[1][2] = 0.237479070111785;
   fWeightMatrix0to1[2][2] = -1.10840312412691;
   fWeightMatrix0to1[3][2] = 0.2136166973283;
   fWeightMatrix0to1[4][2] = 2.96708588429238;
   fWeightMatrix0to1[5][2] = -3.31907671885661;
   fWeightMatrix0to1[6][2] = -0.731246010704869;
   fWeightMatrix0to1[7][2] = -1.18967070460658;
   fWeightMatrix0to1[8][2] = 2.42453295154986;
   fWeightMatrix0to1[9][2] = 6.11131843081591;
   fWeightMatrix0to1[10][2] = -4.29099002710701;
   fWeightMatrix0to1[0][3] = -3.44434372482034;
   fWeightMatrix0to1[1][3] = -0.938191933901121;
   fWeightMatrix0to1[2][3] = 2.78178291363481;
   fWeightMatrix0to1[3][3] = -1.69608619155989;
   fWeightMatrix0to1[4][3] = 2.50787029729101;
   fWeightMatrix0to1[5][3] = -1.96408503946142;
   fWeightMatrix0to1[6][3] = 2.52713568800982;
   fWeightMatrix0to1[7][3] = 1.32620723293778;
   fWeightMatrix0to1[8][3] = 1.84244737987646;
   fWeightMatrix0to1[9][3] = 3.38755877643479;
   fWeightMatrix0to1[10][3] = -0.291191771852067;
   fWeightMatrix0to1[0][4] = -0.879125091145677;
   fWeightMatrix0to1[1][4] = 56.9499747485662;
   fWeightMatrix0to1[2][4] = -0.1277800892655;
   fWeightMatrix0to1[3][4] = -60.0919949751989;
   fWeightMatrix0to1[4][4] = 0.382350472511133;
   fWeightMatrix0to1[5][4] = 1.38444553892328;
   fWeightMatrix0to1[6][4] = 0.419814737183615;
   fWeightMatrix0to1[7][4] = 1.71048991268904;
   fWeightMatrix0to1[8][4] = -0.0359969007413959;
   fWeightMatrix0to1[9][4] = 3.59558095838399;
   fWeightMatrix0to1[10][4] = -0.729065776231651;
   fWeightMatrix0to1[0][5] = -0.774515564057521;
   fWeightMatrix0to1[1][5] = -67.7578997117348;
   fWeightMatrix0to1[2][5] = -0.500333663620525;
   fWeightMatrix0to1[3][5] = 65.3422000065144;
   fWeightMatrix0to1[4][5] = 0.41346202714198;
   fWeightMatrix0to1[5][5] = -2.68078601125054;
   fWeightMatrix0to1[6][5] = 2.14832404346014;
   fWeightMatrix0to1[7][5] = -2.23593374906075;
   fWeightMatrix0to1[8][5] = -2.34805073570197;
   fWeightMatrix0to1[9][5] = 0.512497679620362;
   fWeightMatrix0to1[10][5] = 1.54706697899157;
   fWeightMatrix0to1[0][6] = -7.64139592604277;
   fWeightMatrix0to1[1][6] = -19.1706913690691;
   fWeightMatrix0to1[2][6] = 6.28905655309506;
   fWeightMatrix0to1[3][6] = 20.5957811485099;
   fWeightMatrix0to1[4][6] = 3.29514871301975;
   fWeightMatrix0to1[5][6] = -4.46171357373776;
   fWeightMatrix0to1[6][6] = 2.44299079347049;
   fWeightMatrix0to1[7][6] = 1.49691444096288;
   fWeightMatrix0to1[8][6] = 4.48312517220205;
   fWeightMatrix0to1[9][6] = 3.10446755211103;
   fWeightMatrix0to1[10][6] = -6.98968785055564;
   // weight matrix from layer 1 to 2
   fWeightMatrix1to2[0][0] = -0.742486815108845;
   fWeightMatrix1to2[0][1] = 3.75037271769599;
   fWeightMatrix1to2[0][2] = 1.17362924811138;
   fWeightMatrix1to2[0][3] = 3.77155451145009;
   fWeightMatrix1to2[0][4] = 1.2681101930736;
   fWeightMatrix1to2[0][5] = -0.878151828885853;
   fWeightMatrix1to2[0][6] = 0.984846674483928;
   fWeightMatrix1to2[0][7] = 0.644670276236746;
   fWeightMatrix1to2[0][8] = 0.387253493183681;
   fWeightMatrix1to2[0][9] = 0.985305117766492;
   fWeightMatrix1to2[0][10] = -0.574723506787622;
   fWeightMatrix1to2[0][11] = -3.4055578003371;
}

inline double ReadMLP::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   if (inputValues.size() != (unsigned int)fLayerSize[0]-1) {
      std::cout << "Input vector needs to be of size " << fLayerSize[0]-1 << std::endl;
      return 0;
   }

   for (int l=0; l<fLayers; l++)
      for (int i=0; i<fLayerSize[l]; i++) fWeights[l][i]=0;

   for (int l=0; l<fLayers-1; l++)
      fWeights[l][fLayerSize[l]-1]=1;

   for (int i=0; i<fLayerSize[0]-1; i++)
      fWeights[0][i]=inputValues[i];

   // layer 0 to 1
   for (int o=0; o<fLayerSize[1]-1; o++) {
      for (int i=0; i<fLayerSize[0]; i++) {
         double inputVal = fWeightMatrix0to1[o][i] * fWeights[0][i];
         fWeights[1][o] += inputVal;
      }
      fWeights[1][o] = ActivationFnc(fWeights[1][o]);
   }
   // layer 1 to 2
   for (int o=0; o<fLayerSize[2]; o++) {
      for (int i=0; i<fLayerSize[1]; i++) {
         double inputVal = fWeightMatrix1to2[o][i] * fWeights[1][i];
         fWeights[2][o] += inputVal;
      }
      fWeights[2][o] = OutputActivationFnc(fWeights[2][o]);
   }

   return fWeights[2][0];
}

double ReadMLP::ActivationFnc(double x) const {
   // hyperbolic tan
   return tanh(x);
}
double ReadMLP::OutputActivationFnc(double x) const {
   // sigmoid
   return 1.0/(1.0+exp(-x));
}
   
// Clean up
inline void ReadMLP::Clear() 
{
   // clean up the arrays
   for (int lIdx = 0; lIdx < 3; lIdx++) {
      delete[] fWeights[lIdx];
   }
}
   inline double ReadMLP::GetMvaValue( const std::vector<double>& inputValues ) const
   {
      // classifier response value
      double retval = 0;

      // classifier response, sanity check first
      if (!IsStatusClean()) {
         std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                   << " because status is dirty" << std::endl;
         retval = 0;
      }
      else {
         if (IsNormalised()) {
            // normalise variables
            std::vector<double> iV;
            iV.reserve(inputValues.size());
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
         else {
            std::vector<double> iV;
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(*varIt);
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
      }

      return retval;
   }

//_______________________________________________________________________
inline void ReadMLP::InitTransform_1()
{
   // Normalization transformation, initialisation
   fMin_1[0][0] = 0.500480353832;
   fMax_1[0][0] = 6.90776395798;
   fMin_1[1][0] = 0.500001788139;
   fMax_1[1][0] = 7.91416215897;
   fMin_1[2][0] = 0.500001788139;
   fMax_1[2][0] = 7.91416215897;
   fMin_1[0][1] = 0.500025510788;
   fMax_1[0][1] = 7.02179145813;
   fMin_1[1][1] = 0.500000298023;
   fMax_1[1][1] = 8.17114925385;
   fMin_1[2][1] = 0.500000298023;
   fMax_1[2][1] = 8.17114925385;
   fMin_1[0][2] = 0.50002348423;
   fMax_1[0][2] = 6.96095085144;
   fMin_1[1][2] = 0.500001132488;
   fMax_1[1][2] = 7.59029436111;
   fMin_1[2][2] = 0.500001132488;
   fMax_1[2][2] = 7.59029436111;
   fMin_1[0][3] = -93.4947967529;
   fMax_1[0][3] = 116.318656921;
   fMin_1[1][3] = -1067.71142578;
   fMax_1[1][3] = 414.84954834;
   fMin_1[2][3] = -1067.71142578;
   fMax_1[2][3] = 414.84954834;
   fMin_1[0][4] = -78.8165054321;
   fMax_1[0][4] = 87.2235031128;
   fMin_1[1][4] = -255.85874939;
   fMax_1[1][4] = 84.6223602295;
   fMin_1[2][4] = -255.85874939;
   fMax_1[2][4] = 87.2235031128;
   fMin_1[0][5] = -58.1244239807;
   fMax_1[0][5] = 63.0020904541;
   fMin_1[1][5] = -189.184921265;
   fMax_1[1][5] = 143.8074646;
   fMin_1[2][5] = -189.184921265;
   fMax_1[2][5] = 143.8074646;
}

//_______________________________________________________________________
inline void ReadMLP::Transform_1( std::vector<double>& iv, int cls) const
{
   // Normalization transformation
   if (cls < 0 || cls > 2) {
   if (2 > 1 ) cls = 2;
      else cls = 2;
   }
   const int nVar = 6;

   // get indices of used variables

   // define the indices of the variables which are transformed by this transformation
   static std::vector<int> indicesGet;
   static std::vector<int> indicesPut;

   if ( indicesGet.empty() ) { 
      indicesGet.reserve(fNvars);
      indicesGet.push_back( 0);
      indicesGet.push_back( 1);
      indicesGet.push_back( 2);
      indicesGet.push_back( 3);
      indicesGet.push_back( 4);
      indicesGet.push_back( 5);
   } 
   if ( indicesPut.empty() ) { 
      indicesPut.reserve(fNvars);
      indicesPut.push_back( 0);
      indicesPut.push_back( 1);
      indicesPut.push_back( 2);
      indicesPut.push_back( 3);
      indicesPut.push_back( 4);
      indicesPut.push_back( 5);
   } 

   static std::vector<double> dv;
   dv.resize(nVar);
   for (int ivar=0; ivar<nVar; ivar++) dv[ivar] = iv[indicesGet.at(ivar)];
   for (int ivar=0;ivar<6;ivar++) {
      double offset = fMin_1[cls][ivar];
      double scale  = 1.0/(fMax_1[cls][ivar]-fMin_1[cls][ivar]);
      iv[indicesPut.at(ivar)] = (dv[ivar]-offset)*scale * 2 - 1;
   }
}

//_______________________________________________________________________
inline void ReadMLP::InitTransform()
{
   InitTransform_1();
}

//_______________________________________________________________________
inline void ReadMLP::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
   Transform_1( iv, sigOrBgd );
}
