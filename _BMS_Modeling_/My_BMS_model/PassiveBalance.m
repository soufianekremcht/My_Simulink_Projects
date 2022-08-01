function [y1,y2,y3] = PassiveBalance(s1, s2, s3)

s1 = s1*1000;
s2= s2*1000;
s3 = s3*1000;


s1 = int32(s1);
s2 = int32(s2);
s3 = int32(s3);

if s1>s2 || s1>s3
    y1 = 1
else 
    y1 = 0
end

if s2>s1 || s2>s3
    y2 = 1
else 
    y2 = 0
end

if s3>s1 || s3>s2
    y3 = 1
else 
    y3 = 0
end 
    
   
end
