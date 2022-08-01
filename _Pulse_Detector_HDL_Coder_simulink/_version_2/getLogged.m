%
% Copyright 2020 The MathWorks, Inc.
%
function signal_val = getLogged(simout_obj,signal_name)

logs = simout_obj.logsout;

if isempty(logs)
    error('No logged signal found. Make sure ''%s'' is logged in the model',...
        signal_name);
end

sig = logs.getElement(signal_name);
if isempty(sig)
    error('Signal ''%s'' not found. Make sure it is logged and named correctly.',...
        signal_name);
end

signal_val = squeeze(sig.Values.Data);

end
