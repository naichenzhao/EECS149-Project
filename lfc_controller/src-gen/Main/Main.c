// Code generated by the Lingua Franca compiler from:
// file://Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src/Main.lf
#define LOG_LEVEL 2
#define TARGET_FILES_DIRECTORY "/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main"

#include <limits.h>
#include "include/core/platform.h"
#include "include/api/api.h"
#include "include/core/reactor.h"
#include "include/core/reactor_common.h"
#include "include/core/mixed_radix.h"
#include "include/core/port.h"
#include "include/core/environment.h"
int lf_reactor_c_main(int argc, const char* argv[]);
int main(void) {
   return lf_reactor_c_main(0, NULL);
}
void _lf_set_default_command_line_options() {}
#include "_serial.h"
#include "_main_main.h"
typedef enum {
    main_main,
    _num_enclaves
} _enclave_id;
// The global array of environments associated with each enclave
environment_t envs[_num_enclaves];
// 'Create' and initialize the environments in the program
void _lf_create_environments() {
    environment_init(&envs[main_main],main_main,_lf_number_of_workers,2,2,0,0,2,0,0,NULL);
}
// Update the pointer argument to point to the beginning of the environment array
// and return the size of that array
int _lf_get_environments(environment_t ** return_envs) {
   (*return_envs) = (environment_t *) envs;
   return _num_enclaves;
}
// No watchdogs found.
typedef void watchdog_t;
watchdog_t* _lf_watchdogs = NULL;
int _lf_watchdog_count = 0;
void _lf_initialize_trigger_objects() {
    int startup_reaction_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(startup_reaction_count);
    int shutdown_reaction_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(shutdown_reaction_count);
    int reset_reaction_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(reset_reaction_count);
    int timer_triggers_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(timer_triggers_count);
    int modal_state_reset_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(modal_state_reset_count);
    int modal_reactor_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(modal_reactor_count);
    int bank_index;
    SUPPRESS_UNUSED_WARNING(bank_index);
    int watchdog_number = 0;
    SUPPRESS_UNUSED_WARNING(watchdog_number);
    _main_main_main_self_t* main_main_self[1];
    SUPPRESS_UNUSED_WARNING(main_main_self);
    _serial_self_t* main_s_self[1];
    SUPPRESS_UNUSED_WARNING(main_s_self);
    // ***** Start initializing Main of class Main
    main_main_self[0] = new__main_main();
    main_main_self[0]->base.environment = &envs[main_main];
    bank_index = 0; SUPPRESS_UNUSED_WARNING(bank_index);
    envs[main_main].startup_reactions[startup_reaction_count[main_main]++] = &main_main_self[0]->_lf__reaction_0;
    SUPPRESS_UNUSED_WARNING(_lf_watchdog_count);
    { // For scoping
        static int _initial = 0;
        main_main_self[0]->counter = _initial;
    } // End scoping.
    { // For scoping
        static int _initial = 1;
        main_main_self[0]->sign = _initial;
    } // End scoping.
    // Initiaizing timer Main.t.
    main_main_self[0]->_lf__t.offset = MSEC(500);
    main_main_self[0]->_lf__t.period = MSEC(10);
    // Associate timer with the environment of its parent
    envs[main_main].timer_triggers[timer_triggers_count[main_main]++] = &main_main_self[0]->_lf__t;
    main_main_self[0]->_lf__t.mode = NULL;
    // Initiaizing timer Main.t2.
    main_main_self[0]->_lf__t2.offset = 0;
    main_main_self[0]->_lf__t2.period = MSEC(100);
    // Associate timer with the environment of its parent
    envs[main_main].timer_triggers[timer_triggers_count[main_main]++] = &main_main_self[0]->_lf__t2;
    main_main_self[0]->_lf__t2.mode = NULL;
    
    main_main_self[0]->_lf__reaction_0.deadline = NEVER;
    main_main_self[0]->_lf__reaction_1.deadline = NEVER;
    main_main_self[0]->_lf__reaction_2.deadline = NEVER;
    main_main_self[0]->_lf__reaction_3.deadline = NEVER;
    {
        _main_main_main_self_t *self = main_main_self[0];
        // ***** Start initializing Main.s of class Serial
        main_s_self[0] = new__serial();
        main_s_self[0]->base.environment = &envs[main_main];
        bank_index = 0; SUPPRESS_UNUSED_WARNING(bank_index);
        // width of -2 indicates that it is not a multiport.
        main_s_self[0]->_lf_read_width = -2;
        // width of -2 indicates that it is not a multiport.
        main_s_self[0]->_lf_trigger_width = -2;
        envs[main_main].startup_reactions[startup_reaction_count[main_main]++] = &main_s_self[0]->_lf__reaction_0;
        SUPPRESS_UNUSED_WARNING(_lf_watchdog_count);
    
        main_s_self[0]->_lf__reaction_0.deadline = NEVER;
        main_s_self[0]->_lf__reaction_1.deadline = NEVER;
        //***** End initializing Main.s
    }
    //***** End initializing Main
    // **** Start deferred initialize for Main
    {
    
        // Total number of outputs (single ports and multiport channels)
        // produced by reaction_1 of Main.
        main_main_self[0]->_lf__reaction_0.num_outputs = 0;
        {
            int count = 0; SUPPRESS_UNUSED_WARNING(count);
        }
        
        // ** End initialization for reaction 0 of Main
        // Total number of outputs (single ports and multiport channels)
        // produced by reaction_2 of Main.
        main_main_self[0]->_lf__reaction_1.num_outputs = 1;
        // Allocate memory for triggers[] and triggered_sizes[] on the reaction_t
        // struct for this reaction.
        main_main_self[0]->_lf__reaction_1.triggers = (trigger_t***)_lf_allocate(
                1, sizeof(trigger_t**),
                &main_main_self[0]->base.allocations);
        main_main_self[0]->_lf__reaction_1.triggered_sizes = (int*)_lf_allocate(
                1, sizeof(int),
                &main_main_self[0]->base.allocations);
        main_main_self[0]->_lf__reaction_1.output_produced = (bool**)_lf_allocate(
                1, sizeof(bool*),
                &main_main_self[0]->base.allocations);
        {
            int count = 0; SUPPRESS_UNUSED_WARNING(count);
            // Reaction writes to an input of a contained reactor.
            {
                main_main_self[0]->_lf__reaction_1.output_produced[count++] = &main_main_self[0]->_lf_s.trigger.is_present;
            }
        }
        
        // ** End initialization for reaction 1 of Main
        // Total number of outputs (single ports and multiport channels)
        // produced by reaction_3 of Main.
        main_main_self[0]->_lf__reaction_2.num_outputs = 0;
        {
            int count = 0; SUPPRESS_UNUSED_WARNING(count);
        }
        
        // ** End initialization for reaction 2 of Main
        // Total number of outputs (single ports and multiport channels)
        // produced by reaction_4 of Main.
        main_main_self[0]->_lf__reaction_3.num_outputs = 0;
        {
            int count = 0; SUPPRESS_UNUSED_WARNING(count);
        }
        
        // ** End initialization for reaction 3 of Main
    
        // **** Start deferred initialize for Main.s
        {
        
            // Total number of outputs (single ports and multiport channels)
            // produced by reaction_1 of Main.s.
            main_s_self[0]->_lf__reaction_0.num_outputs = 0;
            {
                int count = 0; SUPPRESS_UNUSED_WARNING(count);
            }
            
            // ** End initialization for reaction 0 of Main.s
            // Total number of outputs (single ports and multiport channels)
            // produced by reaction_2 of Main.s.
            main_s_self[0]->_lf__reaction_1.num_outputs = 1;
            // Allocate memory for triggers[] and triggered_sizes[] on the reaction_t
            // struct for this reaction.
            main_s_self[0]->_lf__reaction_1.triggers = (trigger_t***)_lf_allocate(
                    1, sizeof(trigger_t**),
                    &main_s_self[0]->base.allocations);
            main_s_self[0]->_lf__reaction_1.triggered_sizes = (int*)_lf_allocate(
                    1, sizeof(int),
                    &main_s_self[0]->base.allocations);
            main_s_self[0]->_lf__reaction_1.output_produced = (bool**)_lf_allocate(
                    1, sizeof(bool*),
                    &main_s_self[0]->base.allocations);
            {
                int count = 0; SUPPRESS_UNUSED_WARNING(count);
                {
                    main_s_self[0]->_lf__reaction_1.output_produced[count++] = &main_s_self[0]->_lf_read.is_present;
                }
            }
            
            // ** End initialization for reaction 1 of Main.s
            _lf_initialize_template((token_template_t*)
                    &(main_s_self[0]->_lf_read),
            sizeof(uint8_t));
        }
        // **** End of deferred initialize for Main.s
    }
    // **** End of deferred initialize for Main
    // **** Start non-nested deferred initialize for Main
    {
        // Set number of destination reactors for port s.trigger.
        // Iterate over range Main.s.trigger(0,1)->[Main.s.trigger(0,1)].
        {
            int src_runtime = 0; SUPPRESS_UNUSED_WARNING(src_runtime); // Runtime index.
            int src_channel = 0; SUPPRESS_UNUSED_WARNING(src_channel); // Channel index.
            int src_bank = 0; SUPPRESS_UNUSED_WARNING(src_bank); // Bank index.
            int range_count = 0; SUPPRESS_UNUSED_WARNING(range_count);
            main_main_self[src_runtime]->_lf_s.trigger._base.num_destinations = 1;
            main_main_self[src_runtime]->_lf_s.trigger._base.source_reactor = (self_base_t*)main_main_self[src_runtime];
        }
        {
            int triggers_index[1] = { 0 }; // Number of bank members with the reaction.
            // Iterate over range Main.s.trigger(0,1)->[Main.s.trigger(0,1)].
            {
                int src_runtime = 0; SUPPRESS_UNUSED_WARNING(src_runtime); // Runtime index.
                int src_channel = 0; SUPPRESS_UNUSED_WARNING(src_channel); // Channel index.
                int src_bank = 0; SUPPRESS_UNUSED_WARNING(src_bank); // Bank index.
                int range_count = 0; SUPPRESS_UNUSED_WARNING(range_count);
                // Reaction 1 of Main triggers 1 downstream reactions
                // through port Main.s.trigger.
                main_main_self[src_runtime]->_lf__reaction_1.triggered_sizes[triggers_index[src_runtime]] = 1;
                // For reaction 1 of Main, allocate an
                // array of trigger pointers for downstream reactions through port Main.s.trigger
                trigger_t** trigger_array = (trigger_t**)_lf_allocate(
                        1, sizeof(trigger_t*),
                        &main_main_self[src_runtime]->base.allocations); 
                main_main_self[src_runtime]->_lf__reaction_1.triggers[triggers_index[src_runtime]++] = trigger_array;
            }
            for (int i = 0; i < 1; i++) triggers_index[i] = 0;
            // Iterate over ranges Main.s.trigger(0,1)->[Main.s.trigger(0,1)] and Main.s.trigger(0,1).
            {
                int src_runtime = 0; // Runtime index.
                SUPPRESS_UNUSED_WARNING(src_runtime);
                int src_channel = 0; // Channel index.
                SUPPRESS_UNUSED_WARNING(src_channel);
                int src_bank = 0; // Bank index.
                SUPPRESS_UNUSED_WARNING(src_bank);
                // Iterate over range Main.s.trigger(0,1).
                {
                    int dst_runtime = 0; SUPPRESS_UNUSED_WARNING(dst_runtime); // Runtime index.
                    int dst_channel = 0; SUPPRESS_UNUSED_WARNING(dst_channel); // Channel index.
                    int dst_bank = 0; SUPPRESS_UNUSED_WARNING(dst_bank); // Bank index.
                    int range_count = 0; SUPPRESS_UNUSED_WARNING(range_count);
                    // Point to destination port Main.s.trigger's trigger struct.
                    main_main_self[src_runtime]->_lf__reaction_1.triggers[triggers_index[src_runtime] + src_channel][0] = &main_s_self[dst_runtime]->_lf__trigger;
                }
            }
        }
    
        // **** Start non-nested deferred initialize for Main.s
        {
        
            // For reference counting, set num_destinations for port Main.s.read.
            // Iterate over range Main.s.read(0,1)->[Main.s.read(0,1)].
            {
                int src_runtime = 0; SUPPRESS_UNUSED_WARNING(src_runtime); // Runtime index.
                int src_channel = 0; SUPPRESS_UNUSED_WARNING(src_channel); // Channel index.
                int src_bank = 0; SUPPRESS_UNUSED_WARNING(src_bank); // Bank index.
                int range_count = 0; SUPPRESS_UNUSED_WARNING(range_count);
                main_s_self[src_runtime]->_lf_read._base.num_destinations = 1;
                main_s_self[src_runtime]->_lf_read._base.source_reactor = (self_base_t*)main_s_self[src_runtime];
            }
            {
                int triggers_index[1] = { 0 }; // Number of bank members with the reaction.
                // Iterate over range Main.s.read(0,1)->[Main.s.read(0,1)].
                {
                    int src_runtime = 0; SUPPRESS_UNUSED_WARNING(src_runtime); // Runtime index.
                    int src_channel = 0; SUPPRESS_UNUSED_WARNING(src_channel); // Channel index.
                    int src_bank = 0; SUPPRESS_UNUSED_WARNING(src_bank); // Bank index.
                    int range_count = 0; SUPPRESS_UNUSED_WARNING(range_count);
                    // Reaction 1 of Main.s triggers 1 downstream reactions
                    // through port Main.s.read.
                    main_s_self[src_runtime]->_lf__reaction_1.triggered_sizes[triggers_index[src_runtime]] = 1;
                    // For reaction 1 of Main.s, allocate an
                    // array of trigger pointers for downstream reactions through port Main.s.read
                    trigger_t** trigger_array = (trigger_t**)_lf_allocate(
                            1, sizeof(trigger_t*),
                            &main_s_self[src_runtime]->base.allocations); 
                    main_s_self[src_runtime]->_lf__reaction_1.triggers[triggers_index[src_runtime]++] = trigger_array;
                }
                for (int i = 0; i < 1; i++) triggers_index[i] = 0;
                // Iterate over ranges Main.s.read(0,1)->[Main.s.read(0,1)] and Main.s.read(0,1).
                {
                    int src_runtime = 0; // Runtime index.
                    SUPPRESS_UNUSED_WARNING(src_runtime);
                    int src_channel = 0; // Channel index.
                    SUPPRESS_UNUSED_WARNING(src_channel);
                    int src_bank = 0; // Bank index.
                    SUPPRESS_UNUSED_WARNING(src_bank);
                    // Iterate over range Main.s.read(0,1).
                    {
                        int dst_runtime = 0; SUPPRESS_UNUSED_WARNING(dst_runtime); // Runtime index.
                        int dst_channel = 0; SUPPRESS_UNUSED_WARNING(dst_channel); // Channel index.
                        int dst_bank = 0; SUPPRESS_UNUSED_WARNING(dst_bank); // Bank index.
                        int range_count = 0; SUPPRESS_UNUSED_WARNING(range_count);
                        // Port Main.s.read has reactions in its parent's parent.
                        // Point to the trigger struct for those reactions.
                        main_s_self[src_runtime]->_lf__reaction_1.triggers[triggers_index[src_runtime] + src_channel][0] = &main_main_self[dst_runtime]->_lf_s.read_trigger;
                    }
                }
            }
        
        }
        // **** End of non-nested deferred initialize for Main.s
    }
    // **** End of non-nested deferred initialize for Main
    // Connect inputs and outputs for reactor Main.
    // Connect inputs and outputs for reactor Main.s.
    // Connect Main.s.trigger(0,1)->[Main.s.trigger(0,1)] to port Main.s.trigger(0,1)
    // Iterate over ranges Main.s.trigger(0,1)->[Main.s.trigger(0,1)] and Main.s.trigger(0,1).
    {
        int src_runtime = 0; // Runtime index.
        SUPPRESS_UNUSED_WARNING(src_runtime);
        int src_channel = 0; // Channel index.
        SUPPRESS_UNUSED_WARNING(src_channel);
        int src_bank = 0; // Bank index.
        SUPPRESS_UNUSED_WARNING(src_bank);
        // Iterate over range Main.s.trigger(0,1).
        {
            int dst_runtime = 0; SUPPRESS_UNUSED_WARNING(dst_runtime); // Runtime index.
            int dst_channel = 0; SUPPRESS_UNUSED_WARNING(dst_channel); // Channel index.
            int dst_bank = 0; SUPPRESS_UNUSED_WARNING(dst_bank); // Bank index.
            int range_count = 0; SUPPRESS_UNUSED_WARNING(range_count);
            main_s_self[dst_runtime]->_lf_trigger = (_serial_trigger_t*)&main_main_self[src_runtime]->_lf_s.trigger;
        }
    }
    // Connect Main.s.read(0,1)->[Main.s.read(0,1)] to port Main.s.read(0,1)
    // Iterate over ranges Main.s.read(0,1)->[Main.s.read(0,1)] and Main.s.read(0,1).
    {
        int src_runtime = 0; // Runtime index.
        SUPPRESS_UNUSED_WARNING(src_runtime);
        int src_channel = 0; // Channel index.
        SUPPRESS_UNUSED_WARNING(src_channel);
        int src_bank = 0; // Bank index.
        SUPPRESS_UNUSED_WARNING(src_bank);
        // Iterate over range Main.s.read(0,1).
        {
            int dst_runtime = 0; SUPPRESS_UNUSED_WARNING(dst_runtime); // Runtime index.
            int dst_channel = 0; SUPPRESS_UNUSED_WARNING(dst_channel); // Channel index.
            int dst_bank = 0; SUPPRESS_UNUSED_WARNING(dst_bank); // Bank index.
            int range_count = 0; SUPPRESS_UNUSED_WARNING(range_count);
            main_main_self[dst_runtime]->_lf_s.read = (_serial_read_t*)&main_s_self[src_runtime]->_lf_read;
        }
    }
    {
    }
    // Add port Main.s.trigger to array of is_present fields.
    {
        int count = 0; SUPPRESS_UNUSED_WARNING(count);
        {
            {
                envs[main_main].is_present_fields[0 + count] = &main_main_self[0]->_lf_s.trigger.is_present;
                #ifdef FEDERATED_DECENTRALIZED
                envs[main_main]._lf_intended_tag_fields[0 + count] = &main_main_self[0]->_lf_s.trigger.intended_tag;
                #endif // FEDERATED_DECENTRALIZED
                count++;
            }
        }
    }
    {
        int count = 0; SUPPRESS_UNUSED_WARNING(count);
        {
            // Add port Main.s.read to array of is_present fields.
            envs[main_main].is_present_fields[1 + count] = &main_s_self[0]->_lf_read.is_present;
            #ifdef FEDERATED_DECENTRALIZED
            // Add port Main.s.read to array of intended_tag fields.
            envs[main_main]._lf_intended_tag_fields[1 + count] = &main_s_self[0]->_lf_read.intended_tag;
            #endif // FEDERATED_DECENTRALIZED
            count++;
        }
    }
    
    // Set reaction priorities for ReactorInstance Main
    {
        main_main_self[0]->_lf__reaction_0.chain_id = 1;
        // index is the OR of level 0 and 
        // deadline 9223372036854775807 shifted left 16 bits.
        main_main_self[0]->_lf__reaction_0.index = 0xffffffffffff0000LL;
        main_main_self[0]->_lf__reaction_1.chain_id = 1;
        // index is the OR of level 1 and 
        // deadline 9223372036854775807 shifted left 16 bits.
        main_main_self[0]->_lf__reaction_1.index = 0xffffffffffff0001LL;
        main_main_self[0]->_lf__reaction_2.chain_id = 1;
        // index is the OR of level 2 and 
        // deadline 9223372036854775807 shifted left 16 bits.
        main_main_self[0]->_lf__reaction_2.index = 0xffffffffffff0002LL;
        main_main_self[0]->_lf__reaction_3.chain_id = 1;
        // index is the OR of level 3 and 
        // deadline 9223372036854775807 shifted left 16 bits.
        main_main_self[0]->_lf__reaction_3.index = 0xffffffffffff0003LL;
    
        // Set reaction priorities for ReactorInstance Main.s
        {
            main_s_self[0]->_lf__reaction_0.chain_id = 1;
            // index is the OR of level 0 and 
            // deadline 9223372036854775807 shifted left 16 bits.
            main_s_self[0]->_lf__reaction_0.index = 0xffffffffffff0000LL;
            main_s_self[0]->_lf__reaction_1.chain_id = 1;
            // index is the OR of level 2 and 
            // deadline 9223372036854775807 shifted left 16 bits.
            main_s_self[0]->_lf__reaction_1.index = 0xffffffffffff0002LL;
        }
    
    }
    

    #ifdef EXECUTABLE_PREAMBLE
    _lf_executable_preamble(&envs[0]);
    #endif
    #ifdef FEDERATED
    initialize_triggers_for_federate();
    #endif // FEDERATED
}
void logical_tag_complete(tag_t tag_to_send) {
#ifdef FEDERATED_CENTRALIZED
        _lf_logical_tag_complete(tag_to_send);
#endif // FEDERATED_CENTRALIZED

}
#ifndef FEDERATED
void terminate_execution(environment_t* env) {}
#endif
