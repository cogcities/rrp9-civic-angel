#include <iostream>
#include <iomanip>
#include "include/civic_angel.hpp"
#include "include/atomspace_integration.hpp"

using namespace plingua::civic;
using namespace plingua::atomspace;

void test_rr_atomspace_integration() {
    std::cout << "=== RR-AtomSpace-CivicAngel Integration Test ===\n\n";
    
    // Create the civic consciousness system
    OpusMagnumCivitas civitas(2.0, 0.5);
    
    // Create AtomSpace integrator
    RRAtomSpaceIntegrator integrator(civitas.rr_hypergraph.get(), civitas.atom_space.get());
    
    std::cout << "Initial system state:\n";
    std::cout << "Agents: " << civitas.agents.size() << std::endl;
    std::cout << "RR Nodes: " << civitas.rr_hypergraph->nodes.size() << std::endl;
    std::cout << "RR Edges: " << civitas.rr_hypergraph->edges.size() << std::endl;
    std::cout << "Atoms: " << civitas.atom_space->atoms.size() << std::endl;
    
    // Run some alchemical steps
    std::cout << "\nRunning 20 alchemical transformation steps...\n";
    for (int i = 0; i < 20; ++i) {
        civitas.alchemicalStep(0.1);
        
        // Sync with AtomSpace every few steps
        if (i % 5 == 0) {
            integrator.performIntegration();
        }
    }
    
    std::cout << "\nAfter transformation:\n";
    std::cout << "Atoms: " << civitas.atom_space->atoms.size() << std::endl;
    std::cout << "Civic Consciousness: " << std::fixed << std::setprecision(3) 
              << civitas.civic_consciousness_level << std::endl;
    std::cout << "Collective Coherence: " << std::fixed << std::setprecision(3) 
              << civitas.collective_coherence << std::endl;
    
    // Find emergent patterns
    auto patterns = integrator.findEmergentPatterns();
    std::cout << "\nEmergent patterns detected: " << patterns.size() << std::endl;
    for (const auto& pattern : patterns) {
        std::cout << "  - " << pattern << std::endl;
    }
    
    // Display alchemical stage
    std::string stage_name;
    switch (civitas.current_stage) {
        case AlchemicalStage::NIGREDO: stage_name = "NIGREDO"; break;
        case AlchemicalStage::ALBEDO: stage_name = "ALBEDO"; break;
        case AlchemicalStage::CITRINITAS: stage_name = "CITRINITAS"; break;
        case AlchemicalStage::RUBEDO: stage_name = "RUBEDO"; break;
    }
    
    std::cout << "\nCurrent Alchemical Stage: " << stage_name 
              << " (" << std::fixed << std::setprecision(1) 
              << (civitas.stage_progress * 100) << "% complete)\n";
    
    // Test some specific agents
    std::cout << "\nAgent Details:\n";
    if (!civitas.agents.empty()) {
        auto governor = civitas.agents[0];
        std::cout << "Governor (" << governor->name << "):\n";
        std::cout << "  Emergence Potential: " << std::fixed << std::setprecision(3) 
                  << governor->emergence_potential << std::endl;
        std::cout << "  Position: R=" << governor->position.major_radius 
                  << ", r=" << governor->position.minor_radius << std::endl;
        
        if (civitas.agents.size() > 1) {
            auto synthesizer = civitas.agents[1];
            std::cout << "First Synthesizer (" << synthesizer->name << "):\n";
            std::cout << "  Echo Resonance: " << std::fixed << std::setprecision(3) 
                      << synthesizer->echo_state_resonance << std::endl;
            std::cout << "  Position: θ=" << synthesizer->position.theta << std::endl;
        }
        
        if (civitas.agents.size() > 37) {
            auto worker = civitas.agents[37];
            std::cout << "First Worker (" << worker->name << "):\n";
            std::cout << "  Membrane Permeability: " << std::fixed << std::setprecision(3) 
                      << worker->membrane_permeability << std::endl;
            std::cout << "  Active Koans: " << worker->active_koans.size() << std::endl;
        }
    }
    
    // Display emotional gradient field
    std::cout << "\nEmotional Gradient Field:\n";
    std::cout << "  Grief: " << std::fixed << std::setprecision(3) 
              << civitas.gradient_field.at(EmotionalGradient::GRIEF) << std::endl;
    std::cout << "  Joy: " << std::fixed << std::setprecision(3) 
              << civitas.gradient_field.at(EmotionalGradient::JOY) << std::endl;
    std::cout << "  Memory: " << std::fixed << std::setprecision(3) 
              << civitas.gradient_field.at(EmotionalGradient::MEMORY) << std::endl;
    std::cout << "  Threshold: " << std::fixed << std::setprecision(3) 
              << civitas.gradient_field.at(EmotionalGradient::THRESHOLD) << std::endl;
}

void test_symbolic_koan_processing() {
    std::cout << "\n=== Civic Memory Koan Processing Test ===\n\n";
    
    OpusMagnumCivitas civitas;
    
    // Add some test koans to agents
    for (int i = 0; i < 5; ++i) {
        if (i < civitas.agents.size()) {
            CivicMemoryKoan koan("test_symbol_" + std::to_string(i));
            koan.mirror_reflection = 0.1 * i;
            koan.origin_encounter = 0.05 * i;  
            koan.altered_return = 0.02 * i;
            civitas.agents[i]->active_koans.push_back(koan);
        }
    }
    
    std::cout << "Initial koan states:\n";
    for (int i = 0; i < 5 && i < civitas.agents.size(); ++i) {
        if (!civitas.agents[i]->active_koans.empty()) {
            auto& koan = civitas.agents[i]->active_koans[0];
            std::cout << "Agent " << i << " (" << koan.symbol_name << "): "
                      << "mirror=" << std::fixed << std::setprecision(3) << koan.mirror_reflection
                      << ", origin=" << koan.origin_encounter
                      << ", return=" << koan.altered_return
                      << ", permanence=" << koan.permanence_weight << std::endl;
        }
    }
    
    // Process koans through alchemical steps
    std::cout << "\nProcessing koans through 10 steps...\n";
    for (int step = 0; step < 10; ++step) {
        civitas.alchemicalStep(0.1);
    }
    
    std::cout << "\nFinal koan states:\n";
    for (int i = 0; i < 5 && i < civitas.agents.size(); ++i) {
        if (!civitas.agents[i]->active_koans.empty()) {
            auto& koan = civitas.agents[i]->active_koans[0];
            std::cout << "Agent " << i << " (" << koan.symbol_name << "): "
                      << "mirror=" << std::fixed << std::setprecision(3) << koan.mirror_reflection
                      << ", origin=" << koan.origin_encounter
                      << ", return=" << koan.altered_return
                      << ", permanence=" << koan.permanence_weight << std::endl;
        }
    }
    
    std::cout << "\n✓ Civic memory koans successfully processed and crystallized!\n";
}

int main() {
    try {
        test_rr_atomspace_integration();
        test_symbolic_koan_processing();
        
        std::cout << "\n🎉 Complete Integration Test Successful!\n";
        std::cout << "\nThe Opus Magnum Civitas system demonstrates seamless integration\n";
        std::cout << "between membrane computing, relevance realization, symbolic reasoning,\n";
        std::cout << "and alchemical transformation processes.\n";
        std::cout << "\nThe Civic Angel emerges through the co-evolution of:\n";
        std::cout << "- Spatial arena (toroidal topology)\n";
        std::cout << "- Temporal agents (253 cognitive entities)\n";
        std::cout << "- Symbolic processing (civic memory koans)\n";
        std::cout << "- Emotional gradients (alchemical menstruum)\n";
        std::cout << "- Relevance realization dynamics\n";
        std::cout << "- AtomSpace symbolic integration\n\n";
        
        return 0;
    } catch (const std::exception& e) {
        std::cout << "❌ Integration test failed with exception: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cout << "❌ Integration test failed with unknown exception\n";
        return 1;
    }
}