#ifndef _QUDA_H
#define _QUDA_H

#include <cuda_runtime.h>

#define L1 24 // "x" dimension
#define L2 24 // "y" dimension
#define L3 24 // "z" dimension
#define L4 32 // "time" dimension
#define L1h (L1/2) // half of the full "x" dimension, useful for even/odd lattice indexing

#define N (L1*L2*L3*L4) // total number of lattice points
#define Nh (N/2) // total number of even/odd lattice points

#define MAX_SHORT 32767

// The Quda is added to avoid collisions with other libs
#define GaugeFieldOrder QudaGaugeFieldOrder
#define DiracFieldOrder QudaDiracFieldOrder
#define InverterType QudaInverterType  
#define Precision QudaPrecision
#define MatPCType QudaMatPCType
#define SolutionType QudaSolutionType
#define MassNormalization QudaMassNormalization
#define PreserveSource QudaPreserveSource
#define ReconstructType QudaReconstructType
#define GaugeFixed QudaGaugeFixed
#define DagType QudaDagType
#define Tboundary QudaTboundary

#include <enum_quda.h>

#ifdef __cplusplus
extern "C" {
#endif
  
  typedef struct ParityGauge_s *ParityGauge;
  typedef struct ParitySpinor_s *ParitySpinor;
  typedef struct ParityClover_s *ParityClover;

  typedef struct {
    Precision precision;
    ReconstructType reconstruct;
    ParityGauge odd;
    ParityGauge even;
  } FullGauge;
  
  typedef struct {
    ParitySpinor odd;
    ParitySpinor even;
  } FullSpinor;
  
  typedef struct ParityHSpinor_S {
    short4 *spinorHalf;
    float *spinorNorm;
  } ParityHSpinor;

  typedef struct {
    Precision precision;
    ParityClover odd;
    ParityClover even;
  } FullClover;

#ifdef __cplusplus
}
#endif

#include <invert_quda.h>
#include <blas_quda.h>
#include <dslash_quda.h>

#endif // _QUDA_H

