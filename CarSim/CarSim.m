%http://www.e34.de/tuning/Drehmoment-MP.gif
x = [500, 1500, 2500, 3000, 3250, 3500, 4000, 5000]/60;
y = [40, 70, 95, 110, 110, 110, 95, 75];

a = polyfit(x, y, 2);

xneu = linspace(500/60, 5000/60, 100);
yneu = polyval(a, xneu);

plot(x, y, xneu, yneu);

