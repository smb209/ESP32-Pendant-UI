import { useState } from 'react';
import { Home, RefreshCw, Target, Gauge, Power } from 'lucide-react';

type Axis = 'X' | 'Y' | 'Z';
type StepSize = 100 | 10 | 1;
type MachineState = 'IDLE' | 'RUN' | 'PAUSED';
type Tab = 'MAIN' | 'MACROS' | 'SETUP';

export default function App() {
  const [selectedAxis, setSelectedAxis] = useState<Axis>('X');
  const [stepSize, setStepSize] = useState<StepSize>(0.01);
  const [machineState, setMachineState] = useState<MachineState>('IDLE');
  const [activeTab, setActiveTab] = useState<Tab>('MAIN');
  const [position, setPosition] = useState({ X: -123.456, Y: 0.0, Z: -45.678 });
  const [feedRate, setFeedRate] = useState(100);
  const [spindleOn, setSpindleOn] = useState(false);
  const [workZero, setWorkZero] = useState(true);

  const axisColors = {
    X: '#3B82F6',
    Y: '#10B981',
    Z: '#F59E0B',
  };

  const stateColors = {
    IDLE: '#06B6D4',
    RUN: '#10B981',
    PAUSED: '#F59E0B',
  };

  return (
    <div className="min-h-screen bg-black flex items-center justify-center p-8">
      <div className="relative w-[400px] h-[400px]">
        {/* Circular screen container */}
        <div className="absolute inset-0 rounded-full bg-[#111318] border-2 border-[#222630] overflow-hidden shadow-2xl">
          
          {/* Top status arc */}
          <div className="absolute top-0 left-0 right-0 h-[50px] flex items-center justify-between px-12 text-[11px]">
            <div className="flex items-center gap-2">
              <div 
                className="px-2 py-0.5 rounded"
                style={{ backgroundColor: stateColors[machineState] + '30', color: stateColors[machineState] }}
              >
                {machineState}
              </div>
            </div>
            <div className="flex items-center gap-2">
              <span className={spindleOn ? 'text-green-400' : 'text-gray-500'}>
                {spindleOn ? 'ON' : 'OFF'}
              </span>
              <div className="w-2 h-2 rounded-full bg-green-400"></div>
            </div>
          </div>

          {/* Central control group */}
          <div className="absolute top-1/2 left-1/2 -translate-x-1/2 -translate-y-1/2 -mt-4 flex flex-col items-center gap-3">
            {/* Top controls - Feed and Spindle */}
            <div className="flex items-center justify-center gap-6">
              {/* Feed override */}
              <button
                onClick={() => setFeedRate((f) => (f === 100 ? 50 : 100))}
                className="w-[56px] h-[56px] rounded-full bg-[#1A1D23] border border-[#2A2D35] flex items-center justify-center text-gray-400 hover:text-white hover:border-gray-500 transition-all"
              >
                <Gauge size={20} />
              </button>

              {/* Spindle control */}
              <button
                onClick={() => setSpindleOn(!spindleOn)}
                className={`w-[56px] h-[56px] rounded-full border flex items-center justify-center transition-all ${
                  spindleOn
                    ? 'bg-green-500/20 border-green-500 text-green-400'
                    : 'bg-[#1A1D23] border-[#2A2D35] text-gray-400'
                }`}
              >
                <Power size={20} />
              </button>
            </div>

            {/* Central DRO */}
            <div className="w-[220px]">
              <div className="bg-[#181B1F] rounded-2xl p-3 border border-[#2A2D35]">
                {/* Axis label and Feed rate */}
                <div className="flex items-center justify-between mb-2">
                  <div 
                    className="inline-block px-2.5 py-0.5 rounded-lg"
                    style={{ backgroundColor: axisColors[selectedAxis] }}
                  >
                    <span className="text-white">{selectedAxis}</span>
                  </div>
                  <div className="text-gray-400 text-[11px]">F {feedRate}%</div>
                </div>
                
                {/* Position readout */}
                <div className="flex items-baseline justify-center gap-2">
                  <span className="text-white text-[38px] tracking-tight">
                    {position[selectedAxis].toFixed(3)}
                  </span>
                  <span className="text-gray-400 text-sm">mm</span>
                </div>
              </div>
            </div>

            {/* Bottom controls - Home, Jog, Zero */}
            <div className="flex items-center justify-center gap-6">
              {/* Home */}
              <button
                onClick={() => setPosition({ X: 0, Y: 0, Z: 0 })}
                className="w-[56px] h-[56px] rounded-full bg-[#1A1D23] border border-[#2A2D35] flex items-center justify-center text-gray-400 hover:text-white hover:border-gray-500 transition-all"
              >
                <Home size={24} />
              </button>

              {/* Jog control indicator */}
              <div className="w-[56px] h-[56px] rounded-full bg-[#1A1D23] border border-[#2A2D35] flex items-center justify-center text-gray-400">
                <RefreshCw size={20} />
              </div>

              {/* Zero toggle */}
              <button
                onClick={() => setWorkZero(!workZero)}
                className={`w-[56px] h-[56px] rounded-full border flex items-center justify-center transition-all ${
                  workZero
                    ? 'bg-blue-500/20 border-blue-500 text-blue-400'
                    : 'bg-[#1A1D23] border-[#2A2D35] text-gray-400'
                }`}
              >
                <Target size={24} />
              </button>
            </div>
          </div>

          {/* Left side - Axis selection */}
          <div className="absolute left-[32px] top-1/2 -translate-y-1/2 flex flex-col gap-2">
            {(['X', 'Y', 'Z'] as Axis[]).map((axis) => (
              <button
                key={axis}
                onClick={() => setSelectedAxis(axis)}
                className={`w-[48px] h-[48px] rounded-xl flex items-center justify-center transition-all ${
                  selectedAxis === axis
                    ? 'bg-[#2A2D35] text-white border-2'
                    : 'bg-[#1A1D23] text-gray-500 border border-[#2A2D35]'
                }`}
                style={selectedAxis === axis ? { borderColor: axisColors[axis] } : {}}
              >
                {axis}
              </button>
            ))}
          </div>

          {/* Right side - Step size selection */}
          <div className="absolute right-[32px] top-1/2 -translate-y-1/2 flex flex-col gap-2">
            {([100, 10, 1] as StepSize[]).map((step) => (
              <button
                key={step}
                onClick={() => setStepSize(step)}
                  className={`w-[48px] h-[40px] rounded-xl flex items-center justify-center text-sm transition-all ${
                  stepSize === step
                    ? 'bg-[#2A2D35] text-white border border-cyan-500'
                    : 'bg-[#1A1D23] text-gray-500 border border-[#2A2D35]'
                }`}
              >
                {step.toFixed(0)}
              </button>
            ))}
          </div>

          {/* Bottom navigation segmented panel */}
          <div className="absolute bottom-[32px] left-1/2 -translate-x-1/2 flex items-center bg-[#1A1D23] border border-[#2A2D35] rounded-full p-1">
            {(['MAIN', 'MACROS', 'SETUP'] as Tab[]).map((tab) => (
              <button
                key={tab}
                onClick={() => setActiveTab(tab)}
                className={`px-5 py-2 rounded-full text-[11px] tracking-wide transition-all ${
                  activeTab === tab
                    ? 'bg-[#2A2D35] text-white border border-cyan-500'
                    : 'bg-transparent text-gray-400 border border-transparent'
                }`}
              >
                {tab}
              </button>
            ))}
          </div>

          {/* Outer ring markers */}
          <svg className="absolute inset-0 w-full h-full pointer-events-none" viewBox="0 0 400 400">
            {/* Partial arc from bottom-left to bottom-right through top */}
            <path
              d="M 200 200 m -134.35 134.35 A 190 190 0 1 1 334.35 334.35"
              fill="none"
              stroke="#2A2D35"
              strokeWidth="1"
            />
            {/* Radial tick marks - only from 135° to 45° going clockwise through top */}
            {[...Array(10)].map((_, i) => {
              // Start at 135° and go to 405° (wraps to 45°) in 10 steps = 27° intervals
              const angleDeg = 135 + (i * 27);
              const angle = (angleDeg) * (Math.PI / 180);
              const x1 = 200 + Math.cos(angle) * 180;
              const y1 = 200 + Math.sin(angle) * 180;
              const x2 = 200 + Math.cos(angle) * 190;
              const y2 = 200 + Math.sin(angle) * 190;
              return (
                <line
                  key={i}
                  x1={x1}
                  y1={y1}
                  x2={x2}
                  y2={y2}
                  stroke="#2A2D35"
                  strokeWidth="2"
                />
              );
            })}
          </svg>

        </div>
      </div>
    </div>
  );
}
