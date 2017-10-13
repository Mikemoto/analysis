#ifndef __RICHParticleID_H__
#define __RICHParticleID_H__

#include <fun4all/SubsysReco.h>
#include <math.h>

class TTree;
class TFile;
class TH1D;

class PHCompositeNode;
class PHG4TruthInfoContainer;
class PHG4Hit;
class PHG4HitContainer;
class SvtxTrackMap;
class SvtxTrack_FastSim;

class eic_dual_rich;

class RICHParticleID : public SubsysReco
{

public:

  RICHParticleID(std::string tracksname, std::string richname, std::string filename);

  int
  Init(PHCompositeNode*);
  int
  process_event(PHCompositeNode*);
  int
  End(PHCompositeNode*);


private:

  /** reset all output tree variables */
  void reset_tree_vars();

  /** initialize output tree */
  int init_tree();

  /** calculate emission angle for single track and photon */
  double calculate_emission_angle( double m_emi[3], PHG4Hit *hit_i );

  /** get position from track state */
  bool get_position_from_track_state(  SvtxTrack_FastSim * track, std::string statename, double arr_pos[3] );


//  /* fill 'fake' track map with truth info */
//  SvtxTrackMap* fill_truth_trackmap(PHG4TruthInfoContainer*, PHG4HitContainer*);

  bool _verbose;

  int _ievent;

  /* Collection sotring track information */
  std::string _trackmap_name;

  /* Hit collection storing RICH photon hits */
  std::string _richhits_name;

  /* ROOT file to store output ROOT tree */
  std::string _foutname;
  TFile *_fout_root;

  /* output tree and variables */
  TTree* _tree_rich;
  float _theta_true;
  float _theta_reco;

  /* analyzer object */
  eic_dual_rich *_analyzer;

};

#endif // __RICHParticleID_H__