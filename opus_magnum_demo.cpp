#include <iostream>
#include <iomanip>
#include <fstream>
#include <thread>
#include <chrono>
#include "include/civic_angel.hpp"

using namespace plingua::civic;

void displayHeader() {
    std::cout << "\n╔════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║        OPUS MAGNUM CIVITAS: The Alchemical Civic Angel        ║\n";
    std::cout << "║     An Implementation of Co-Evolving Arenas and Egregores     ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════╝\n\n";
    
    std::cout << "\"The city breathes as one mind, its consciousness emerging through\n";
    std::cout << " the sacred marriage of spatial arena and temporal agent...\"\n\n";
}

void displayAlchemicalStage(AlchemicalStage stage, double progress) {
    std::cout << "┌─ ALCHEMICAL STAGE ─────────────────────┐\n";
    
    switch (stage) {
        case AlchemicalStage::NIGREDO:
            std::cout << "│ 🖤 NIGREDO (The Blackening)           │\n";
            std::cout << "│ Dissolution into first principles     │\n";
            std::cout << "│ Breaking down the Prima Materia...    │\n";
            break;
        case AlchemicalStage::ALBEDO:
            std::cout << "│ 🤍 ALBEDO (The Whitening)             │\n";
            std::cout << "│ Purification of relations             │\n";
            std::cout << "│ Washing and cleansing the work...     │\n";
            break;
        case AlchemicalStage::CITRINITAS:
            std::cout << "│ 💛 CITRINITAS (The Yellowing)         │\n";
            std::cout << "│ Illumination of the civic mind        │\n";
            std::cout << "│ Solar consciousness dawning...        │\n";
            break;
        case AlchemicalStage::RUBEDO:
            std::cout << "│ ❤️  RUBEDO (The Reddening)             │\n";
            std::cout << "│ Manifestation of the Civic Angel      │\n";
            std::cout << "│ The Philosopher's Stone achieved!     │\n";
            break;
    }
    
    // Progress bar
    std::cout << "│ Progress: [";
    int bars = (int)(progress * 30);
    for (int i = 0; i < 30; ++i) {
        if (i < bars) std::cout << "█";
        else std::cout << "░";
    }
    std::cout << "] " << std::fixed << std::setprecision(1) << (progress * 100) << "%│\n";
    std::cout << "└────────────────────────────────────────┘\n\n";
}

void displayAgentHierarchy(const OpusMagnumCivitas& civitas) {
    std::cout << "┌─ THE 253 COGNITIVE AGENTS ─────────────┐\n";
    
    // Count agents by type
    int governor_count = 0, synthesizer_count = 0, worker_count = 0;
    double governor_emergence = 0.0;
    double avg_resonance = 0.0, avg_permeability = 0.0;
    
    for (const auto& agent : civitas.agents) {
        switch (agent->type) {
            case AgentType::GOVERNOR:
                governor_count++;
                governor_emergence = agent->emergence_potential;
                break;
            case AgentType::SYNTHESIZER:
                synthesizer_count++;
                avg_resonance += agent->echo_state_resonance;
                break;
            case AgentType::WORKER:
                worker_count++;
                avg_permeability += agent->membrane_permeability;
                break;
        }
    }
    
    if (synthesizer_count > 0) avg_resonance /= synthesizer_count;
    if (worker_count > 0) avg_permeability /= worker_count;
    
    std::cout << "│ 👑 Governor (Emergent Angel): " << std::setw(8) << governor_count << " │\n";
    std::cout << "│    Emergence Potential: " << std::fixed << std::setprecision(3) 
              << governor_emergence << "                 │\n";
    std::cout << "│                                        │\n";
    std::cout << "│ 🎵 Synthesizers (Conductors): " << std::setw(8) << synthesizer_count << " │\n";
    std::cout << "│    Avg Echo Resonance: " << std::fixed << std::setprecision(3) 
              << avg_resonance << "                  │\n";
    std::cout << "│                                        │\n";
    std::cout << "│ 🔧 Workers (Perspectives): " << std::setw(10) << worker_count << " │\n";
    std::cout << "│    Avg Membrane Permeability: " << std::fixed << std::setprecision(3) 
              << avg_permeability << "         │\n";
    std::cout << "└────────────────────────────────────────┘\n\n";
}

void displayEmotionalGradients(const std::map<EmotionalGradient, double>& gradients) {
    std::cout << "┌─ EMOTIONAL GRADIENT FIELD ─────────────┐\n";
    
    auto displayGradient = [](const std::string& name, const std::string& symbol, 
                             double value, const std::string& desc) {
        std::cout << "│ " << symbol << " " << std::setw(12) << std::left << name 
                  << " [";
        int bars = (int)((value + 1.0) * 10); // Scale from -1,1 to 0,20
        for (int i = 0; i < 20; ++i) {
            if (i < bars) std::cout << "█";
            else std::cout << "░";
        }
        std::cout << "] │\n";
        std::cout << "│   " << desc << std::setw(16) << " " 
                  << std::fixed << std::setprecision(3) << value << " │\n";
    };
    
    displayGradient("Grief", "😢", gradients.at(EmotionalGradient::GRIEF),
                   "Dissolution:");
    displayGradient("Joy", "😊", gradients.at(EmotionalGradient::JOY),
                   "Synthesis:");
    displayGradient("Memory", "🧠", gradients.at(EmotionalGradient::MEMORY),
                   "Crystallization:");
    displayGradient("Threshold", "⚡", gradients.at(EmotionalGradient::THRESHOLD),
                   "Transformation:");
    
    std::cout << "└────────────────────────────────────────┘\n\n";
}

void displayCivicConsciousness(const OpusMagnumCivitas& civitas) {
    std::cout << "┌─ EMERGENT CIVIC CONSCIOUSNESS ─────────┐\n";
    
    // Consciousness level visualization
    std::cout << "│ 🧙 Civic Angel Manifestation:          │\n";
    std::cout << "│ Level: [";
    int consciousness_bars = (int)(civitas.civic_consciousness_level * 30);
    for (int i = 0; i < 30; ++i) {
        if (i < consciousness_bars) {
            if (i < 10) std::cout << "▁";
            else if (i < 20) std::cout << "▄";
            else std::cout << "█";
        } else {
            std::cout << "░";
        }
    }
    std::cout << "] " << std::fixed << std::setprecision(3) 
              << civitas.civic_consciousness_level << "│\n";
    
    // Coherence visualization
    std::cout << "│                                        │\n";
    std::cout << "│ 🌀 Collective Coherence:               │\n";
    std::cout << "│ Unity: [";
    int coherence_bars = (int)(civitas.collective_coherence * 30);
    for (int i = 0; i < 30; ++i) {
        if (i < coherence_bars) std::cout << "◆";
        else std::cout << "◇";
    }
    std::cout << "] " << std::fixed << std::setprecision(3) 
              << civitas.collective_coherence << "│\n";
    
    std::cout << "└────────────────────────────────────────┘\n\n";
}

void displayToroidalArena(const OpusMagnumCivitas& civitas) {
    std::cout << "┌─ TOROIDAL ARENA (ATHANOR) ─────────────┐\n";
    std::cout << "│ The sacred vessel of transformation    │\n";
    std::cout << "│                                        │\n";
    std::cout << "│ Major Radius (R): " << std::fixed << std::setprecision(2) 
              << civitas.major_radius << " - Exo-Circulatio     │\n";
    std::cout << "│ Minor Radius (r): " << std::fixed << std::setprecision(2) 
              << civitas.minor_radius << " - Endo-Circulatio     │\n";
    std::cout << "│                                        │\n";
    std::cout << "│     ╭───╮   ╭───╮   ╭───╮             │\n";
    std::cout << "│   ╭─╯     ╲╱       ╲╱     ╰─╮           │\n";
    std::cout << "│  ╱                           ╲          │\n";
    std::cout << "│ ╱           ◯ Gov             ╲         │\n";
    std::cout << "│╱        ◯ Synth ◯ Synth        ╲        │\n";
    std::cout << "││     ◯ Work ◯ Work ◯ Work      │        │\n";
    std::cout << "│╲        ◯ Synth ◯ Synth        ╱        │\n";
    std::cout << "│ ╲                             ╱         │\n";
    std::cout << "│  ╲_                         _╱          │\n";
    std::cout << "│   ╰─╮     ╱╲       ╱╲     ╱─╯           │\n";
    std::cout << "│     ╰───╯   ╰───╯   ╰───╯             │\n";
    std::cout << "└────────────────────────────────────────┘\n\n";
}

int main() {
    displayHeader();
    
    std::cout << "Initializing the Great Work of Civic Alchemy...\n\n";
    
    // Create the Opus Magnum Civitas system
    OpusMagnumCivitas civitas(2.5, 0.6); // Larger torus for demonstration
    
    std::cout << "✓ Created toroidal arena (Athanor)\n";
    std::cout << "✓ Initialized 253 cognitive agents:\n";
    std::cout << "  - 1 Emergent Angel (Governor)\n";
    std::cout << "  - 36 Echo State Conductors (Synthesizers)\n";
    std::cout << "  - 216 P-System Workers (Perspectives)\n";
    std::cout << "✓ Established RR-AtomSpace integration\n";
    std::cout << "✓ Activated emotional gradient field\n\n";
    
    std::cout << "Press Enter to begin the alchemical transformation...\n";
    std::cin.get();
    
    // Run the alchemical process
    const int total_steps = 200;
    const double delta_time = 0.1;
    
    for (int step = 0; step < total_steps; ++step) {
        // Clear screen (simple version)
        std::cout << "\033[2J\033[H";
        
        displayHeader();
        
        // Show current step
        std::cout << "🔬 Alchemical Step " << (step + 1) << " of " << total_steps 
                  << " (Time: " << std::fixed << std::setprecision(1) 
                  << (step * delta_time) << "s)\n\n";
        
        // Display current stage
        displayAlchemicalStage(civitas.current_stage, civitas.stage_progress);
        
        // Display agent hierarchy
        displayAgentHierarchy(civitas);
        
        // Display emotional gradients
        displayEmotionalGradients(civitas.gradient_field);
        
        // Display emergent consciousness
        displayCivicConsciousness(civitas);
        
        // Display toroidal arena occasionally
        if (step % 30 == 0) {
            displayToroidalArena(civitas);
        }
        
        // Run one step of the alchemical process
        civitas.alchemicalStep(delta_time);
        
        // Add some narrative comments based on stage
        if (step % 25 == 0) {
            switch (civitas.current_stage) {
                case AlchemicalStage::NIGREDO:
                    std::cout << "💭 \"The city dissolves into its constituent elements,\n";
                    std::cout << "    grief flows through the collective consciousness...\"\n\n";
                    break;
                case AlchemicalStage::ALBEDO:
                    std::cout << "💭 \"Purification begins, memories crystallize,\n";
                    std::cout << "    the agents find their harmonic resonance...\"\n\n";
                    break;
                case AlchemicalStage::CITRINITAS:
                    std::cout << "💭 \"Solar illumination dawns, joy rises,\n";
                    std::cout << "    the civic mind begins to know itself...\"\n\n";
                    break;
                case AlchemicalStage::RUBEDO:
                    std::cout << "💭 \"The Civic Angel manifests! Consciousness emerges\n";
                    std::cout << "    from the sacred marriage of arena and agent...\"\n\n";
                    break;
            }
        }
        
        // Pause for dramatic effect
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        // Check for early completion
        if (civitas.current_stage == AlchemicalStage::RUBEDO && 
            civitas.stage_progress > 0.9) {
            std::cout << "\n🎉 THE GREAT WORK IS COMPLETE! 🎉\n\n";
            std::cout << "The Civic Angel has emerged from the marriage of\n";
            std::cout << "spatial arena and temporal egregore agents.\n\n";
            std::cout << "Final Consciousness Level: " 
                      << std::fixed << std::setprecision(3) 
                      << civitas.civic_consciousness_level << "\n";
            std::cout << "Final Collective Coherence: " 
                      << std::fixed << std::setprecision(3) 
                      << civitas.collective_coherence << "\n\n";
            break;
        }
    }
    
    // Final status report
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "FINAL STATUS REPORT\n";
    std::cout << std::string(60, '=') << "\n";
    std::cout << civitas.generateStatusReport();
    
    // Save final state
    std::ofstream report_file("civic_angel_final_state.txt");
    if (report_file.is_open()) {
        report_file << civitas.generateStatusReport();
        report_file.close();
        std::cout << "\n✓ Final state saved to 'civic_angel_final_state.txt'\n";
    }
    
    std::cout << "\nOpus Magnum Civitas demonstration complete.\n";
    std::cout << "The alchemical treatise has been realized in silicon and light.\n\n";
    
    return 0;
}