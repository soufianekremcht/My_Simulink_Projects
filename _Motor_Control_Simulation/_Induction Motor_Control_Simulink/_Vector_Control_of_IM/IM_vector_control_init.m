clc;
clear;


Rr=3.805;
J=0.031;
fr=0;
p=2;
Rs=4.85;
M=0.258;
Ls=0.274;
Lr=0.274;

R=[Rs 0 0 0 ; 0 Rs 0 0; 0 0 Rr 0; 0 0 0 Rr]
L=[Ls 0 M 0 ; 0 Ls 0 M; M 0 Lr 0; 0 M 0 Lr]

% R=[Rs 0 0; 0 Rs 0; 0 0 Rr]

sig=1-M^2/(Ls*Lr)
Tr=Lr/Rr
Ts=Ls/Rs
B=[1/(Ls*sig) 0 0 0; 0 1/(Ls*sig) 0 0; -M/(Ls*Lr*sig) 0 0 0; 0 -M/(Ls*Lr*sig) 0 0 ]

A1=[-1/(Ts*sig) 0 M/(Ls*Tr*sig) 0; 0 -1/(Ts*sig) 0 M/(Ls*Tr*sig); M/(Lr*Ts*sig) 0 -1/(Tr*sig) 0 ; 0 M/(Ls*Ts*sig) 0 -1/(Tr*sig)]
A2=[0 1 0 0; -1 0 0 0 ; 0 0 0 1 ; 0 0 -1 0]
A3=[0 1/sig 0 M/(Ls*sig); -1/sig 0 -M/(Ls*sig) 0 ; 0 -M/(Lr*sig) 0 -M^2/(Ls*Lr*sig) ; M/(Lr*sig) 0 M^2/(Ls*Lr*sig) 0]

C= [Rs 0 0; 0 Rs 0];
D=[0 -sig*Ls 0; sig*Ls 0 M/Lr];

T=[2/3 -1/3 -1/3;-1/3 2/3 -1/3;-1/3 -1/3 2/3];
fpor = 5000;

