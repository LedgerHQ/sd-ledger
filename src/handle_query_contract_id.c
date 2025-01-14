#include "stakedao_plugin.h"

void handle_query_contract_id(ethQueryContractID_t *msg) {
    stakedao_parameters_t *context = (stakedao_parameters_t *) msg->pluginContext;

    strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);

    switch (context->selectorIndex) {
        case VAULT_DEPOSIT:
        case VAULT_DEPOSIT_ALL:
        case OPT_DEPOSIT_ETH:
        case OPT_DEPOSIT_UNDERLYING:
        case OPT_DEPOSIT_CRVLP:
        case SANCTUARY_ENTER:
        case PREMIUM_STAKE:
        case LP_DEPOSIT:
        case PALACE_STAKE:
            strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);
            strlcpy(msg->version, "Deposit", msg->versionLength);
            break;
        case PREMIUM_WITHDRAW:
        case LP_WITHDRAW:
        case PALACE_WITHDRAW:
        case VAULT_WITHDRAW:
        case OPT_WITHDRAW_ETH:
        case OPT_WITHDRAW_CRVLP:
        case OPT_WITHDRAW_UNDERLYING:
        case SANCTUARY_LEAVE:
            strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);
            strlcpy(msg->version, "Withdraw", msg->versionLength);
            break;
        case PREMIUM_GETREWARD:
        case REWARDS_CLAIM:
        case ANGLE_GET_REWARD:
            strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);
            strlcpy(msg->version, "Get Reward", msg->versionLength);
            break;
        case PREMIUM_EXIT:
            strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);
            strlcpy(msg->version, "Exit", msg->versionLength);
            break;
        case NFT_STAKE:
            strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);
            strlcpy(msg->version, "Stake", msg->versionLength);
            break;
        case NFT_UNSTAKE:
            strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);
            strlcpy(msg->version, "Unstake", msg->versionLength);
            break;
        case CURVE_ADD_L_2:
        case CURVE_ADD_L_3:
        case CURVE_ADD_L_3_UNDER:
            strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);
            strlcpy(msg->version, "Add Liquidity", msg->versionLength);
            break;
        default:
            PRINTF("Selector Index :%d not supported\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    msg->result = ETH_PLUGIN_RESULT_OK;
}
