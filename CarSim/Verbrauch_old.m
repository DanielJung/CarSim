clc, clear, close all;
x = [1100, 2, 400;
    1100, 5, 280;
    1100, 11, 245;
    1200, 22.5, 295;
    1500, 12.5, 240;
    1500, 15, 240;
    2000, 5, 280;
    2000, 10, 240;
    2000, 12.5, 220;
    2000, 16, 240;
    2500, 8, 250;
    2500, 22, 250;
    3000, 2, 400;
    3000, 5, 280;
    3000, 22.5, 255;
    3300, 12.5, 240;
    4000, 12.5, 250;
    4000, 22.5, 295;
    5000, 5, 320;
    5000, 10, 280;
    5400, 17, 295;
    5600, 10, 300;
    6000, 2.5, 400;
    6000, 10, 400;];

dx1 = 2500/60;
dx2 = 10^5*0.5*12.5*1.33*10^-3/(2*pi)/1.8;

x(:, 2) = 10^5*0.5*x(:, 2)*1.33*10^-3/(2*pi)/1.8;
x(:, 1) = x(:, 1)/60;
x(:, 3) = x(:, 3)/1000/2.32;

m = length(x(:, 3));
n = 14;

scaleX = 62.5;
scaleY = 5.5;

A = zeros(m, n);
b = zeros(m, 1);

for i=1:m
    A(i, 1) = x(i, 1)^2;
    A(i, 2) = x(i, 1);
    A(i, 3) = 1;
    
    A(i, 4) = x(i, 2)^2;
    A(i, 5) = x(i, 2);
    
    A(i, 6) = x(i, 1)^2*x(i, 2);
    A(i, 7) = x(i, 1)*x(i, 2)^2;
    A(i, 8) = x(i, 1)^2*x(i, 2)^2;
    
    A(i, 9) = exp(x(i, 1)/scaleX);
    A(i, 10) = exp(-x(i, 1)/scaleX);
    
    A(i, 11) = exp(x(i, 2)/scaleY);
    A(i, 12) = exp(-x(i, 2)/scaleY);
    
    A(i, 13) = exp((x(i, 1)/scaleX)*x(i, 2)/scaleY);
    A(i, 14) = exp(-(x(i, 1)/scaleX)*x(i, 2)/scaleY);
    
    b(i, 1) = x(i, 3);
end

i = m-1;
A(i, 1) = 2*dx1;
A(i, 2) = 1;
A(i, 3) = 0;

A(i, 4) = 0;
A(i, 5) = 0;

A(i, 6) = 2*dx1*dx2;
A(i, 7) = dx2^2;
A(i, 8) = 2*dx1*dx2^2;

A(i, 9) = exp(dx1/scaleX);
A(i, 10) = -exp(-dx1/scaleX);

A(i, 11) = 0;
A(i, 12) = 0;

A(i, 13) = dx2*exp(dx1/scaleX*dx2/scaleY);
A(i, 14) = -dx2*exp(-dx1/scaleX*dx2/scaleY);

b(i, 1) = 0;

i = m;
A(i, 1) = 0;
A(i, 2) = 0;
A(i, 3) = 0;

A(i, 4) = 2*dx2;
A(i, 5) = 1;

A(i, 6) = dx1^2;
A(i, 7) = 2*dx1*dx2;
A(i, 8) = 2*dx1^2*dx2;

A(i, 9) = 0;
A(i, 10) = 0;

A(i, 11) = exp(dx2/scaleY);
A(i, 12) = -exp(-dx2/scaleY);

A(i, 13) = dx1*exp(dx1/scaleX*dx2/scaleY);
A(i, 14) = -dx1*exp(-dx1/scaleX*dx2/scaleY);

b(i, 1) = 0;


z = A\b;

[X, Y] = meshgrid(linspace(1000/60, 6000/60, 200), linspace(0, 120, 200));
Z = z(1)*X.^2+z(2)*X+z(3)+z(4)*Y.^2+z(5)*Y+z(6)*X.^2.*Y+z(7)*X.*Y.^2+z(8)*X.^2.*Y.^2+z(9)*exp(X/scaleX)+z(10)*exp(-X/scaleX)+z(11)*exp(Y/scaleY)+z(12)*exp(-Y/scaleY)+z(13)*exp((X/scaleX).*Y/scaleY)+z(14)*exp(-(X/scaleX).*Y/scaleY);

% Z = z(1)*X.^2+
% z(2)*X+
% z(3)+
% z(4)*Y.^2+
% z(5)*Y+
% z(6)*X.^2.*Y+
% z(7)*X.*Y.^2+
% z(8)*X.^2.*Y.^2+
% z(9)*exp(X/scaleX)+
% z(10)*exp(-X/scaleX)+
% z(11)*exp(Y/scaleY)+
% z(12)*exp(-Y/scaleY)+
% z(13)*exp((X/scaleX).*Y/scaleY)+
% z(14)*exp(-(X/scaleX).*Y/scaleY);

figure;
surf(X, Y, Z);

figure;
[c, h] = contourf(X, Y, Z, [220, 240, 245, 250, 260, 270, 280, 300, 320, 360, 400]/2.32/1000);
clabel(c, h);
xlabel('Drehzahl [1/s]');
ylabel('Drehmoment [Nm]');

X = 4000/60;
Y = 120;
Z = z(1)*X.^2+z(2)*X+z(3)+z(4)*Y.^2+z(5)*Y+z(6)*X.^2.*Y+z(7)*X.*Y.^2+z(8)*X.^2.*Y.^2+z(9)*exp(X/scaleX)+z(10)*exp(-X/scaleX)+z(11)*exp(Y/scaleY)+z(12)*exp(-Y/scaleY)+z(13)*exp((X/scaleX).*Y/scaleY)+z(14)*exp(-(X/scaleX).*Y/scaleY);
