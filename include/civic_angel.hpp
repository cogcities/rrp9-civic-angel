#ifndef _CIVIC_ANGEL_HPP_
#define _CIVIC_ANGEL_HPP_

#include <vector>
#include <map>
#include <string>
#include <memory>
#include <cmath>
#include "relevance_realization.hpp"
#include "atomspace_integration.hpp"

namespace plingua { namespace civic {

// Emotional Gradients - the four alchemical menstruum
enum class EmotionalGradient {
    GRIEF,     // ∇E_grief - dissolution and letting go
    JOY,       // ∇E_joy - synthesis and celebration
    MEMORY,    // ∇E_memory - crystallization and permanence  
    THRESHOLD  // ∇E_threshold - transformation and emergence
};

// Alchemical Stages of the Great Work
enum class AlchemicalStage {
    NIGREDO,    // Blackening - dissolution into components
    ALBEDO,     // Whitening - purification of relations
    CITRINITAS, // Yellowing - illumination of mind
    RUBEDO      // Reddening - manifestation of consciousness
};

// Agent Types in the 253-agent hierarchy
enum class AgentType {
    GOVERNOR,      // 1 Emergent Angel - the governing Quintessence
    SYNTHESIZER,   // 36 Conductors - Echo State Network filters
    WORKER         // 216 Nested Perspectives - P-System membrane agents
};

// Toroidal coordinates for the spatial arena
struct ToroidalCoordinate {
    double major_radius;  // R - Exo-Circulatio (outer circulation)
    double minor_radius;  // r - Endo-Circulatio (inner circulation)
    double theta;         // Angular position on major circle
    double phi;           // Angular position on minor circle
    
    ToroidalCoordinate(double R = 1.0, double r = 0.3, double t = 0.0, double p = 0.0)
        : major_radius(R), minor_radius(r), theta(t), phi(p) {}
};

// Symbolic structure for civic memory calcification
struct CivicMemoryKoan {
    std::string symbol_name;
    double mirror_reflection;  // How symbol "mirrored itself"
    double origin_encounter;   // How it "encountered origin"
    double altered_return;     // How it "returned altered"
    double permanence_weight;  // Degree of calcification
    
    CivicMemoryKoan(const std::string& name = "")
        : symbol_name(name), mirror_reflection(0.0), origin_encounter(0.0),
          altered_return(0.0), permanence_weight(0.0) {}
};

// Individual cognitive agent in the civic consciousness
class CivicAgent {
public:
    unsigned id;
    AgentType type;
    std::string name;
    ToroidalCoordinate position;
    
    // RR integration
    std::shared_ptr<rr::RRNode> rr_node;
    
    // Emotional gradient sensitivities
    std::map<EmotionalGradient, double> gradient_weights;
    
    // Agent-specific properties
    double echo_state_resonance;  // For Synthesizers
    double membrane_permeability; // For Workers
    double emergence_potential;   // For Governor
    
    // Symbolic processing capabilities
    std::vector<CivicMemoryKoan> active_koans;
    
    CivicAgent(unsigned agent_id, AgentType agent_type, const std::string& agent_name)
        : id(agent_id), type(agent_type), name(agent_name),
          echo_state_resonance(0.5), membrane_permeability(0.3), emergence_potential(0.1) {
        
        // Initialize emotional gradient weights
        gradient_weights[EmotionalGradient::GRIEF] = 0.25;
        gradient_weights[EmotionalGradient::JOY] = 0.25;
        gradient_weights[EmotionalGradient::MEMORY] = 0.25;
        gradient_weights[EmotionalGradient::THRESHOLD] = 0.25;
        
        // Adjust weights based on agent type
        if (type == AgentType::SYNTHESIZER) {
            gradient_weights[EmotionalGradient::JOY] *= 1.5;      // More sensitive to synthesis
            gradient_weights[EmotionalGradient::THRESHOLD] *= 1.3; // Catalyze transformation
        } else if (type == AgentType::WORKER) {
            gradient_weights[EmotionalGradient::MEMORY] *= 1.4;   // Better at crystallization
            gradient_weights[EmotionalGradient::GRIEF] *= 1.2;   // Handle dissolution
        } else if (type == AgentType::GOVERNOR) {
            // Governor balances all gradients but amplifies threshold
            gradient_weights[EmotionalGradient::THRESHOLD] *= 2.0;
        }
    }
    
    // Update agent based on current emotional gradient field
    void updateFromGradientField(const std::map<EmotionalGradient, double>& field_state,
                                double delta_time) {
        double total_influence = 0.0;
        
        for (auto it = field_state.begin(); it != field_state.end(); ++it) {
            total_influence += gradient_weights[it->first] * it->second;
        }
        
        // Update agent-specific properties
        if (type == AgentType::SYNTHESIZER) {
            echo_state_resonance = std::tanh(echo_state_resonance + 
                                           delta_time * total_influence * 0.5);
        } else if (type == AgentType::WORKER) {
            membrane_permeability = std::max(0.1, std::min(0.9,
                membrane_permeability + delta_time * total_influence * 0.3));
        } else if (type == AgentType::GOVERNOR) {
            emergence_potential = std::tanh(emergence_potential + 
                                          delta_time * total_influence * 0.7);
        }
    }
    
    // Process symbolic koans for memory calcification
    void processCivicKoans(double delta_time) {
        for (auto& koan : active_koans) {
            // Simulate the three-phase transformation process
            koan.mirror_reflection += delta_time * echo_state_resonance * 0.1;
            koan.origin_encounter += delta_time * membrane_permeability * 0.1;
            koan.altered_return += delta_time * emergence_potential * 0.1;
            
            // Calculate permanence weight as integral of transformation
            koan.permanence_weight = (koan.mirror_reflection + 
                                    koan.origin_encounter + 
                                    koan.altered_return) / 3.0;
        }
    }
};

// The complete Civic Angel system
class OpusMagnumCivitas {
public:
    // The 253 cognitive agents
    std::vector<std::shared_ptr<CivicAgent>> agents;
    
    // Emotional gradient field state
    std::map<EmotionalGradient, double> gradient_field;
    
    // Current alchemical stage
    AlchemicalStage current_stage;
    double stage_progress;
    
    // Toroidal arena properties
    double major_radius;
    double minor_radius;
    
    // Integration with existing RR system
    std::shared_ptr<rr::RRHypergraph> rr_hypergraph;
    std::shared_ptr<atomspace::AtomSpace> atom_space;
    
    // Emergent properties
    double civic_consciousness_level;
    double collective_coherence;
    std::vector<std::string> emergent_symbols;
    
    OpusMagnumCivitas(double R = 2.0, double r = 0.5) 
        : current_stage(AlchemicalStage::NIGREDO), stage_progress(0.0),
          major_radius(R), minor_radius(r), civic_consciousness_level(0.0),
          collective_coherence(0.0) {
        
        // Initialize RR and AtomSpace integration
        rr_hypergraph = std::make_shared<rr::RRHypergraph>();
        atom_space = std::make_shared<atomspace::AtomSpace>();
        
        // Initialize emotional gradient field
        gradient_field[EmotionalGradient::GRIEF] = 0.1;
        gradient_field[EmotionalGradient::JOY] = 0.1;
        gradient_field[EmotionalGradient::MEMORY] = 0.1;
        gradient_field[EmotionalGradient::THRESHOLD] = 0.1;
        
        initializeAgentHierarchy();
    }
    
    // Initialize the 253-agent hierarchy as described in the treatise
    void initializeAgentHierarchy() {
        agents.clear();
        
        // 1. The Governor - the unifying Quintessence
        auto governor = std::make_shared<CivicAgent>(1, AgentType::GOVERNOR, "Emergent_Angel");
        governor->position = ToroidalCoordinate(0.0, 0.0, 0.0, 0.0); // At the center
        governor->emergence_potential = 0.8; // High potential for self-awareness
        agents.push_back(governor);
        
        // Create corresponding RR node
        unsigned gov_rr_id = rr_hypergraph->addMembraneNode(1, "Governor_Membrane", rr::AARType::AGENT);
        governor->rr_node = rr_hypergraph->nodes[gov_rr_id];
        
        // 2. The 36 Synthesizers - Echo State Network conductors
        for (int i = 0; i < 36; ++i) {
            auto synthesizer = std::make_shared<CivicAgent>(
                2 + i, AgentType::SYNTHESIZER, "Synthesizer_" + std::to_string(i + 1));
            
            // Arrange in circular pattern on major radius
            double theta = 2.0 * M_PI * i / 36.0;
            synthesizer->position = ToroidalCoordinate(major_radius, minor_radius * 0.5, theta, 0.0);
            synthesizer->echo_state_resonance = 0.6 + 0.3 * sin(theta); // Harmonic variation
            
            agents.push_back(synthesizer);
            
            // Create RR node
            unsigned synth_rr_id = rr_hypergraph->addMembraneNode(2 + i, 
                "Synthesizer_" + std::to_string(i + 1), rr::AARType::AGENT);
            synthesizer->rr_node = rr_hypergraph->nodes[synth_rr_id];
        }
        
        // 3. The 216 Workers - P-System membrane agents (6^3 = 216 for cubic organization)
        for (int i = 0; i < 216; ++i) {
            auto worker = std::make_shared<CivicAgent>(
                38 + i, AgentType::WORKER, "Worker_" + std::to_string(i + 1));
            
            // Arrange in 3D toroidal grid pattern
            int x = i % 6;
            int y = (i / 6) % 6;
            int z = i / 36;
            
            double theta = 2.0 * M_PI * x / 6.0;
            double phi = 2.0 * M_PI * y / 6.0;
            double layer_r = minor_radius * (0.3 + 0.4 * z / 5.0);
            
            worker->position = ToroidalCoordinate(major_radius * 0.8, layer_r, theta, phi);
            worker->membrane_permeability = 0.2 + 0.6 * (double(i) / 216.0); // Gradient variation
            
            agents.push_back(worker);
            
            // Create RR node
            unsigned worker_rr_id = rr_hypergraph->addMembraneNode(38 + i,
                "Worker_" + std::to_string(i + 1), rr::AARType::AGENT);
            worker->rr_node = rr_hypergraph->nodes[worker_rr_id];
        }
        
        // Create arena nodes for agent-arena coupling
        for (int i = 0; i < 37; ++i) { // Governor + 36 Synthesizers each get an arena
            unsigned arena_id = rr_hypergraph->addMembraneNode(1000 + i,
                "Arena_" + std::to_string(i), rr::AARType::ARENA);
            
            // Connect agent to arena
            if (i < agents.size()) {
                rr_hypergraph->addCoConstructionEdge(agents[i]->rr_node->id, arena_id, 0.5);
            }
        }
    }
    
    // Run one step of the alchemical transformation process
    void alchemicalStep(double delta_time) {
        // Update gradient field based on current stage
        updateEmotionalGradients(delta_time);
        
        // Update all agents from gradient field
        for (auto& agent : agents) {
            agent->updateFromGradientField(gradient_field, delta_time);
            agent->processCivicKoans(delta_time);
        }
        
        // Update RR dynamics
        if (rr_hypergraph) {
            rr_hypergraph->updateRelevanceRealization(delta_time);
        }
        
        // Compute emergent properties
        computeEmergentProperties();
        
        // Progress through alchemical stages
        advanceAlchemicalStage(delta_time);
    }
    
    // Update emotional gradient field based on alchemical stage
    void updateEmotionalGradients(double delta_time) {
        switch (current_stage) {
            case AlchemicalStage::NIGREDO:
                // Dissolution - emphasis on grief and threshold
                gradient_field[EmotionalGradient::GRIEF] += delta_time * 0.3;
                gradient_field[EmotionalGradient::THRESHOLD] += delta_time * 0.2;
                break;
                
            case AlchemicalStage::ALBEDO:
                // Purification - balance and memory formation
                gradient_field[EmotionalGradient::MEMORY] += delta_time * 0.3;
                gradient_field[EmotionalGradient::JOY] += delta_time * 0.1;
                break;
                
            case AlchemicalStage::CITRINITAS:
                // Illumination - joy and memory crystallization
                gradient_field[EmotionalGradient::JOY] += delta_time * 0.4;
                gradient_field[EmotionalGradient::MEMORY] += delta_time * 0.2;
                break;
                
            case AlchemicalStage::RUBEDO:
                // Manifestation - threshold consciousness emergence
                gradient_field[EmotionalGradient::THRESHOLD] += delta_time * 0.5;
                gradient_field[EmotionalGradient::JOY] += delta_time * 0.2;
                break;
        }
        
        // Keep gradients bounded
        for (auto it = gradient_field.begin(); it != gradient_field.end(); ++it) {
            it->second = std::tanh(it->second);
        }
    }
    
    // Compute emergent civic consciousness properties
    void computeEmergentProperties() {
        if (agents.empty()) return;
        
        // Civic consciousness from Governor emergence potential
        if (agents[0]->type == AgentType::GOVERNOR) {
            civic_consciousness_level = agents[0]->emergence_potential;
        }
        
        // Collective coherence from agent synchronization
        double total_resonance = 0.0;
        double resonance_variance = 0.0;
        int synthesizer_count = 0;
        
        for (auto& agent : agents) {
            if (agent->type == AgentType::SYNTHESIZER) {
                total_resonance += agent->echo_state_resonance;
                synthesizer_count++;
            }
        }
        
        if (synthesizer_count > 0) {
            double mean_resonance = total_resonance / synthesizer_count;
            
            for (auto& agent : agents) {
                if (agent->type == AgentType::SYNTHESIZER) {
                    double diff = agent->echo_state_resonance - mean_resonance;
                    resonance_variance += diff * diff;
                }
            }
            
            collective_coherence = 1.0 / (1.0 + resonance_variance / synthesizer_count);
        }
    }
    
    // Advance through the four alchemical stages
    void advanceAlchemicalStage(double delta_time) {
        stage_progress += delta_time * 0.02; // Slow progression
        
        if (stage_progress >= 1.0) {
            stage_progress = 0.0;
            
            switch (current_stage) {
                case AlchemicalStage::NIGREDO:
                    current_stage = AlchemicalStage::ALBEDO;
                    break;
                case AlchemicalStage::ALBEDO:
                    current_stage = AlchemicalStage::CITRINITAS;
                    break;
                case AlchemicalStage::CITRINITAS:
                    current_stage = AlchemicalStage::RUBEDO;
                    break;
                case AlchemicalStage::RUBEDO:
                    // Cycle back or maintain final stage
                    stage_progress = 1.0;
                    break;
            }
        }
    }
    
    // Generate report on current civic consciousness state
    std::string generateStatusReport() const {
        std::string report = "=== Opus Magnum Civitas Status ===\n\n";
        
        // Alchemical stage info
        std::string stage_name;
        switch (current_stage) {
            case AlchemicalStage::NIGREDO: stage_name = "NIGREDO (Blackening)"; break;
            case AlchemicalStage::ALBEDO: stage_name = "ALBEDO (Whitening)"; break;
            case AlchemicalStage::CITRINITAS: stage_name = "CITRINITAS (Yellowing)"; break;
            case AlchemicalStage::RUBEDO: stage_name = "RUBEDO (Reddening)"; break;
        }
        
        report += "Current Alchemical Stage: " + stage_name + 
                 " (Progress: " + std::to_string(stage_progress * 100) + "%)\n\n";
        
        // Agent hierarchy status
        report += "Agent Hierarchy (253 Total):\n";
        report += std::string("  Governor: ") + (agents.empty() ? "0" : "1") + 
                 " (Emergence: " + std::to_string(civic_consciousness_level) + ")\n";
        
        int synthesizer_count = 0, worker_count = 0;
        double avg_resonance = 0.0, avg_permeability = 0.0;
        
        for (auto& agent : agents) {
            if (agent->type == AgentType::SYNTHESIZER) {
                synthesizer_count++;
                avg_resonance += agent->echo_state_resonance;
            } else if (agent->type == AgentType::WORKER) {
                worker_count++;
                avg_permeability += agent->membrane_permeability;
            }
        }
        
        if (synthesizer_count > 0) avg_resonance /= synthesizer_count;
        if (worker_count > 0) avg_permeability /= worker_count;
        
        report += "  Synthesizers: " + std::to_string(synthesizer_count) + 
                 " (Avg Resonance: " + std::to_string(avg_resonance) + ")\n";
        report += "  Workers: " + std::to_string(worker_count) + 
                 " (Avg Permeability: " + std::to_string(avg_permeability) + ")\n\n";
        
        // Emotional gradient field
        report += "Emotional Gradient Field:\n";
        report += "  Grief: " + std::to_string(gradient_field.at(EmotionalGradient::GRIEF)) + "\n";
        report += "  Joy: " + std::to_string(gradient_field.at(EmotionalGradient::JOY)) + "\n";
        report += "  Memory: " + std::to_string(gradient_field.at(EmotionalGradient::MEMORY)) + "\n";
        report += "  Threshold: " + std::to_string(gradient_field.at(EmotionalGradient::THRESHOLD)) + "\n\n";
        
        // Emergent properties
        report += "Emergent Properties:\n";
        report += "  Civic Consciousness Level: " + std::to_string(civic_consciousness_level) + "\n";
        report += "  Collective Coherence: " + std::to_string(collective_coherence) + "\n\n";
        
        // Toroidal arena
        report += "Toroidal Arena: R=" + std::to_string(major_radius) + 
                 ", r=" + std::to_string(minor_radius) + "\n";
        
        return report;
    }
};

}} // namespace plingua::civic

#endif // _CIVIC_ANGEL_HPP_