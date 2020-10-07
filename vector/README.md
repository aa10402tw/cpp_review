Table of Contents
=================
  * [Copy vector](#Copy-Vector)
  * [Sort vector](#Sort-Vector)
  * [Diabetic-retinopathy-detection (CNN)](#Diabetic-retinopathy-detection)
  * [Back-Propagation-Through-Time (BPTT)](#Back-Propagation-Through-Time)
  * [Conditional Sequence-to-Sequence Variation Autoencoder (RNN + VAE)](#Conditional-Seq2Seq-VAE)
  * [InfoGAN for MINST (GAN)](#InfoGAN)
  * [Time-Difference Learning for MINST (RL) ](#TD-learning)
  * [DQN & DDPG for Atari Games (DRL)](#DQN_and_DDPG)

## Copy-Vector
vec2.assign(vec.begin(), vec.end());

## Sort-Vector
std::sort(vec.begin(), vec.end());

bool compareInterval(std::vector<int> i1, std::vector<int> i2) { return (i1[0] < i2[0]);}
std::sort(intervals.begin(), intervals.end(), compareInterval);